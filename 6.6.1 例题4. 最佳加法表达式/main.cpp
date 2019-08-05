/**
 * 有一个由1~9组成的数字串, 问如果能将m个加号插入到这个数字串中,在
 * 各种可能形成的表达式中,值最小的那个表达式的值是多少
 */

// V(m, n)表示在n个数字中插入m个加号所能形成的表达式最小值
// if m = 0: V(m,n) = n个数字构成的整数
// if n < m + 1: V(m,n) = inf
// V(m, n) = Min{V(m-1,i) + Num(i+1,n)} (i=m...n-1)

#include <iostream>

int main() {

	return 0;
}

