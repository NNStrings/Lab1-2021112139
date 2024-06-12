CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -fprofile-arcs -ftest-coverage
SRC_DIR = .
TEST_DIR = test
BUILD_DIR = build
RESULT_DIR = results
INC_DIR = -I$(SRC_DIR) -I$(TEST_DIR)/include
LIB_DIR = -L$(TEST_DIR)/lib
LIBS = -lgtest -pthread

TARGET = main
TEST_TARGET = test_main

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))

.PHONY: all clean test exe coverage html

all: $(BUILD_DIR)/$(TARGET) $(BUILD_DIR)/$(TEST_TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -o $@ $^

$(BUILD_DIR)/$(TEST_TARGET): $(filter-out $(BUILD_DIR)/main.o, $(OBJS)) $(TEST_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -o $@ $^ $(LIB_DIR) $(LIBS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -o $@ -c $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INC_DIR) -o $@ -c $<

test: 
	$(BUILD_DIR)/$(TEST_TARGET)
	@./$(BUILD_DIR)/$(TEST_TARGET)

exe:
	./build/main ./test.txt < script.txt

coverage: $(BUILD_DIR)/$(TEST_TARGET)
	@./$(BUILD_DIR)/$(TEST_TARGET)
	@gcov -o $(BUILD_DIR) $(SRCS) $(TEST_SRCS)

html:
	@lcov --directory . --capture --output-file app.info
	@genhtml -o results app.info

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(RESULT_DIR)
	@rm -f *.gcno *.gcda *.gcov *.info *png *jpg
