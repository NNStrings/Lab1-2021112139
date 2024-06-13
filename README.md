# Lab1-2021112139

## 功能

### 返回图的节点数和边数

```bash
v       # 返回图节点数
e       # 返回图边数
```

### 展示图结构

以png的形式展示该图

```bash
showg
```

### 查询桥接词

```bash
bw w1 w2    # 其中w1、w2为查询的两个单词
```

### 根据bridge word生成新文本

```bash
bnw input   # 其中input为读入的文本
```

### 计算两个单词之间的最短路径

```bash
shortp1 w       # 计算w该单词到任意单词的最短路径
shortp2 w1 w2   # 计算w1,w2两个单词之间的最短路径
```

### 随机游走

```bash
rwalk
```

### 退出

```bash
exit
```

## 测试工具

### 代码风格审查工具 ———— cpplint

下载 `cpplint.py` 文件并安装：

```bash
pip install cpplint
```

<div><a href="https://github.com/google/styleguide/blob/gh-pages/cpplint/cpplint.py">文件下载链接</a></div></br>

使用：

```bash
python2 cpplint.py --filter=-build/include *.cpp
```

### 代码静态检查工具 ———— cppcheck

安装：

```bash
sudo apt install cppcheck
```

使用：

```bash
cppcheck --enable=all --suppress=missingInclude --suppress=unusedFunction Lab3-2021112139/
```

### 单元测试工具 ———— google test

安装：

```bash
cd ~/
git clone https://github.com/google/googletest.git
cd googletest
mkdir build && cd build
cmake -DCMAKE_CXX_STANDARD=17 ..
make
sudo make install

cd ..
cp googletest/include/gtest your_project_folder/test/include/
cp googlemock/include/gmock your_project_folder/test/include/gmock
cp build/lib your_project_folder/test/lib
```

### 代码覆盖率工具 ———— gcov 和 lcov

安装：

```bash
sudo apt install lcov
```

运行：

```bash
gcov -o build . test
lcov --directory . --capture --output-file app.info
genhtml -o results app.info
```

## 运行

```bash
make clean          # 清除编译产生的所有文件
make                # 编译程序
make exe            # 运行主程序
make test           # 运行测试文件
make coverage       # 计算代码覆盖率
make html           # 可视化代码覆盖率
```