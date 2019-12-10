## 内容目录
* [牛顿迭代法](./newton-method/README.md)
  * [如何通俗易懂地讲解牛顿迭代法？](<https://blog.csdn.net/ccnt_2012/article/details/81837154>)
* 求不大于n的全部质数
* [计算星期几](#)
* strtok实现
* 排序
## 其他工具

## 算法&数据结构

### 二叉树遍历

#### 中序遍历

* 相当于从左到右遍历，对于二叉搜索树BST，就是从小到大遍历

### Hash

#### 利用质数的乘积作为hash key

* 相关题目：[LeetCode: 49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)

### [康托展开和逆康托展开](https://blog.csdn.net/wbin233/article/details/72998375)

### 线段树

### 优先队列

### 计算星期几（[基姆拉尔森计算公式](https://blog.csdn.net/qq_40772692/article/details/80330346)）

* ```c++
  int _day_of_week(int year, int month, int day=1) {
    if (month == 1 || month == 2) {
      --year;
      month += 12;
    }
    // 0 -- Sunday 1 -- Monday
    return (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 + 1) % 7;
  }
  ```
  
* 相关题目

  * [POJ NOI MATH-7831 计算星期几](http://noi.openjudge.cn/math/7831/) [POJ NOI MATH-7831 计算星期几](https://blog.csdn.net/tigerisland45/article/details/69055252)

### 快速幂

* ```c++
  template <typename T>
  T pow(T x, int n) {
    int ret = 1;
    while (n) {
      if (n & 1) { // 按位与比n%2更快
        ret *= x;
      }
      x *= x;
      n >>= 1;
    }
    return ret;
  }
  ```

### 模拟除法

* ```c++
  // remove sign of operands 
  long div = dividend; 
  long dsr = divisor; 
  div = abs(div);
  dsr = abs(dsr);
  long long  tmp = 0;
  long long quotient = 0;
  // 这里模拟除法运算，二进制的，从第31位一直到第0位
  for(int i = 31; i>= 0; --i) {
      if(tmp + (dsr<<i) <= div) {
          tmp += dsr << i; 
          quotient |= 1LL << i; 
      }
  }
  ```

## 记忆

* 数学函数，cmath头文件

  * [cmath(常用函数)](https://blog.csdn.net/weixin_41183791/article/details/89603259)

* strupr(char []) not in standard c library

* strlwr(char [])

* strcat(char * dest, char * str)

* strchr 查找首次出现字符的位置

* strrchr

* strstr和str1.find(str2) (c++中string类型)

* atoi

* atof

* itoa (windows)

* freopen

* stricmp (..)

* binary_search 找到返回true

* lower_bound 大于等于x（指针）

* upper_bound 大于x（指针）

* pair<T1, T2>

* multiset 
  * lower_bound 大于等于最小
  * upper_bound 小于等于最大
  * find
  * erase
  * insert
  
* set
  
  * 不能有重复元素
  
* multimap

* map
  * 关键字不相等
  * 可以用[]
  
* unordered_map

  * 不用排序，比map快

* max_element

* sort

* partition

* memset

* cctype

* 圆周率PI怎么得

  * ```c++
    #include <cstdio>
    #include <cmath>
    int main() {
        const double pi = acos(-1.0);
        // ...
    }
    ```

---
* double间的比较要通过比较差值是否达到精度要求
* 1e3 默认是double

## ToDos

- [ ] 9.1.1 took 500ms, To Be Optimized
- [ ] 字符串匹配算法（判断是否为子串）[NOI/1.7编程基础之字符串/18:验证子串](http://noi.openjudge.cn/ch0107/18)
- [ ] setprecision为何能表示很大的pow(2, n)