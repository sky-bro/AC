## 文件说明:

main.cpp 输出一个最长公共子序列

main_all.cpp 输出所有最长公共子序列

## 编译

```shell
g++ main.cpp -o main
g++ main_all.cpp -o main_all
```

## 运行

两个串可以通过命令行参数传入或者直接运行，然后输入两个串

输出的前半部分是递归的方式运行的结果，后半部分是非递归方式（递推）的结果

```shell
$ ./main_all ABC CBA
1
size: 3
A
B
C

1
size: 3
A
B
C
```

```shell
$ ./main_all bdcaba abcbdba
4
size: 2
bcba
bdba

4
size: 2
bcba
bdba
```

