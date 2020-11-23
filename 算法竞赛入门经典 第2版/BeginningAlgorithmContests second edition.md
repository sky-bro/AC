> * 适合语言零基础的初学者
> * 算法竞赛主要知识点的入门与拓宽
> * 近200道竞赛真题分析
> * 实用主义的C++和STL讲解
> * 简介、清晰、高效的示例代码


# 第1部分 语言篇

## 第1章 程序设计入门

* 圆周率PI是多少

  ```c++
  #include <cstdio>
  #include <cmath>
  int main() {
      const double pi = acos(-1.0);
      // ...
  }
  ```

* double在scanf时用%lf，printf时用%f

* 交换两个变量swap(T &a, T &b)

  * 三变量法（推荐）

    ```c++
    T t = a;
    a = b;
    b = t;
    ```

  * 两变量法

    * 加法

      ```c++
      if (a==b) return;
      a = a + b;
      b = a - b;
      a = a - b;
      ```

    * 异或1

      ```c++
      if (a==b) return;
      a ^= b;
      b ^= a;
      a ^= b;
      ```

    * 异或2

      ```c++
      if (a==b) return;
      a ^= b ^= a ^= b;
      ```

* 其它数学函数：[cmath(常用函数)](https://blog.csdn.net/weixin_41183791/article/details/89603259)

## 第2章 循环结构程序设计

* 输出long long类型时最好用cout，而不用printf，因为格式化字符串有时是%lld，有时是%l64d

* 使用文件进行输入输出

  * 方法1

    * `freopen("input.txt", "r", stdin);`
    * `freopen("output.txt", "w", stdout);`

  * 方法2: fopen

    * ```c++
      FILE *fin, *fout;
      fin = fopen("data.in", "rb");
      fout = fopen("data.out", "wb");
      fscanf(fin, "%d", &x);
      fprintf(fout, "%d %d %.3f\n", min, max, double(s)/n);
      fclose(fin);
      fclose(fout);
      ```

    * ```c++
      // 如果要改成标准输入输出
      FILE *fin, *fout;
      fin = stdin;
      fout = stdout;
      ```

* 使用宏定义

  * ```c++
    #define LOCAL
    
    #ifdef LOCAL
    //...
    #endif
    ```

* 头文件iomanip: `setprecision(n)`

## 第三章 数组和字符串

* `memcpy(b, a, sizeof(int)*k)` 头文件`string.h`

* 较大的数组应尽量声明在main函数外，否则程序可能无法运行。

* `memset(a, 0, sizeof(a))` 把数组a清零，头文件`string.h`

* `strchr(s, buf[i]) == NULL` 在一个字符串中查找单个字符

* `sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z)` 输出到字符串，应当保证字符数组足够大

* `strcpy(a, b), strcmp(a, b), strcat(a, b)` 赋值、比较、连接

* `fgetc(fin)` 

  * 从打开的文件fin中读取一个字符，应检查它是不是`EOF`然后再将其转换成char值。

  * 从标准输入读取一个字符可以用`getchar`，它等价于`fgetc(stdin)`

  * ```c++
    #include <iostream>
    
    int main(int argc, const char **argv)
    {
        int a, b, c;
        a = fgetc(stdin);
        b = getchar();
        c = fgetc(stdin);
        if (c == EOF)
        {
            fprintf(stdout, "\n%#x %#x eof\n", a, b);
        }
        else
        {
            fprintf(stdout, "%d %d\n", a, b);
        }
        return 0;
    }
    ```

  * 在使用fgetc和getchar时，应该避免写出和操作系统相关的程序

* `fgets(buf, maxn, fin)` 除了在文件结束前没有遇到`"\n"`这种特殊情况外，buf总是以`"\n"`结尾。当一个字符都没有读到时，`fgets`返回NULL

  * `fgets`的标准输入版兄弟`gets`因为没有指明读取的最大字符数，已经被废除：C11标准里，gets函数已被正式删除

* `fputc`和`putchar` 将一个字符输出到文件或者`stdout`

* `ctype.h`

  * `isalpha` 判断是否为字母
  * `isdigit`
  * `isprint`
  * `toupper`
  * `tolower`

* 

## 第4章 函数和递归

## 第5章 C++与STL入门

# 第2部分 基础篇

## 第6章 数据结构基础

## 第7章 暴力求解法

# 第3部分 竞赛篇

## 第8章 高效算法设计

## 第9章 动态规划初步

## 第10章 数学概念与方法

## 第11章 图论模型与算法

## 第12章 高级专题

## 附录A 开发环境与方法