# Lab1-2021112139

## 功能

### 1、读入文本并生成有向图

```bash
make exe
```

### 2、返回图的节点数和边数

```bash
v       # 返回图节点数
e       # 返回图边数
```

### 3、展示图结构

以png的形式展示该图

```bash
showg
```

### 4、查询桥接词

```bash
bw w1 w2    # //其中w1、w2为查询的两个单词
```

### 5、根据bridge word生成新文本

```bash
bnw input   # 其中input为读入的文本
```

### 6、计算两个单词之间的最短路径

```bash
shortp1 w       # 计算w该单词到任意单词的最短路径
shortp2 w1 w2   # 计算w1,w2两个单词之间的最短路径
```

### 7、随机游走

```bash
rwalk
```

### 8、退出

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
python2 cpplint.py *.cpp
```

### 代码静态检查工具 ———— cppcheck

安装：

```bash
sudo apt install cppcheck
```

使用：

```bash
cppcheck --enable=all --suppress=missingInclude --suppress=unusedFunction Lab1-2021112139/
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