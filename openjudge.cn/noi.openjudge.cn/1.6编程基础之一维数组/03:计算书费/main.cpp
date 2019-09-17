/*
下面是一个图书的单价表：
计算概论 28.9 元/本
数据结构与算法 32.7 元/本
数字逻辑 45.6元/本
C++程序设计教程 78 元/本
人工智能 35 元/本
计算机体系结构 86.2 元/本
编译原理 27.8元/本
操作系统 43 元/本
计算机网络 56 元/本
JAVA程序设计 65 元/本
给定每种图书购买的数量，编程计算应付的总费用。
*/

#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  double a[10] = {28.9, 32.7, 45.6, 78, 35,
                  86.2, 27.8, 43, 56, 65};
  int tmp; double sum=0;
  for (int i = 0; i < 10; ++i) {
    cin>>tmp;
    sum += tmp*a[i];
  }
  printf("%.1f\n", sum);
  return 0;
}