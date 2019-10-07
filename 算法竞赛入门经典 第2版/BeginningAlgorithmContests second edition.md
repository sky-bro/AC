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

## 数组和字符串

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