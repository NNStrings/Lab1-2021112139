#include <gtest/gtest.h>
#include "graph.h"

TEST(GraphTest, ExampleTest) {
    Graph G("./test.txt");
    // ASSERT_EQ(G.get_v(), 100);
    // ASSERT_EQ(G.get_e(), 120);
    EXPECT_EQ(G.get_v(), 10);
    EXPECT_EQ(G.get_e(), 12);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
