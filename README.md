## 内容目录
* [牛顿迭代法](./newton-method/README.md)
  * [如何通俗易懂地讲解牛顿迭代法？](<https://blog.csdn.net/ccnt_2012/article/details/81837154>)
* 求不大于n的全部质数
* [计算星期几](#)
* strtok实现
* 排序
## 其他工具

## 算法&数据结构

### Cache

#### Cache替换策略

##### Rand

##### FIFO: 不合适

##### LRU: 挺好

* 最近用到的数据被重用的`概率`比最早用到的数据大的多

##### LFU:

### 字符串匹配

#### Trie (Prefix Tree) 前缀树，字典树

* [leetcode: 208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

##### 插入

##### 查找

##### 前缀查询

##### 删除

1. 删除单词是另一个单词的前缀 -- 只需要把最后一个节点的isWord改成false
2. 除了尾部几个节点没有分支，中间节点有分支 -- 删除到最深的分支节点处

### 两个字符串a和b，a+b大还是b+a大

* naive way

  ```c++
  bool cmp(string& a, string& b)
  {
      return a + b > b + a;
  }
  ```

* smarter way?

  ```c++
  bool cmp(string& a, string& b)
  {
    int blen = b.size();
    int alen = a.size();
    int i = 0;
    for (; i < (alen + blen) && b[i%blen] == a[i%alen]; ++i)
    return a[i%alen] > b[i%blen];
  };
  ```

### 快速选择Quick Select

* [Quick Select: 找到一对无序的数中第 **K** 大，或者第 **K** 小的元素](https://www.cnblogs.com/LinMiaoJia/p/QuickSelect.html)
* [leetcode: 0215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)

### 排序

#### 选择排序 Selection Sort

* 每次选择最小的元素排好

#### 插入排序 Insertion Sort

* 跟玩扑克牌类似，每次插入一个元素到已排序数组合适位置
* 应该比选择排序要快（不用每次遍历所有元素，找到合适位置就停下，而选择排序要遍历所有的才能找到最小元素）
* 尤其对于近乎有序的数组，插入排序更好

#### 冒泡排序 Bubble Sort

* 也是适合对近乎有序的数组排序，但不如插入排序好
* 每次从0下标开始，不断和相邻元素比较并选择是否交换两元素，每次冒泡出一个最大元素

#### 归并排序 Merge Sort

#### 快速排序Quick Sort

#### 希尔排序 Shell's Sort

#### 比较性质排序

#### 计数性质排序

#### 桶排序Bucket Sort

* [leetcode 0164](https://leetcode.com/problems/maximum-gap)

#### 计数排序

#### 快速排序

#### 拓扑排序

* [拓扑排序详解与实现](https://www.cnblogs.com/bigsai/p/11489260.html)

### 双指针

#### 快慢指针

* 判断是否有环
* 判断开始进入环的节点
  * 快慢指针首次相遇了
  * 从相遇点再往后的第n个节点与从头往后的第n个节点，两节点相同

### 二叉树遍历

#### 中序遍历

* 相当于从左到右遍历，对于二叉搜索树BST，就是从小到大遍历
* [二叉树的中序遍历非递归算法](https://blog.csdn.net/billy1900/article/details/86229656)

#### 后序遍历

* [二叉树非递归后序遍历](https://blog.csdn.net/qq_35812205/article/details/96476519)
  * 由于镜像二叉树的先序遍历=原二叉树后序遍历，可以先求出镜像先序，最后reverse一下即可。

### Hash

#### 利用质数的乘积作为hash key

* 相关题目：[LeetCode: 49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)

### [康托展开和逆康托展开](https://blog.csdn.net/wbin233/article/details/72998375)

### 树状数组 Binary Indexed Tree

### 线段树 Segment Tree

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

## 数学 Maths

### 欧拉定理

* 欧拉函数$\varphi(n)\;(n \in N^*)$：小于等于n的正整数中与n互质的数的个数（如$\varphi(3)=2$）
  * $\varphi(1)=1$
  * 因为质数与小于它的每一个正整数都互质，所以如果n是质数，则$\varphi(n)=n-1$
  * 如果$n=p^k\;(p为质数,k\in N^*)$ ，则$\varphi(p^k)=p^k-p^{k-1}$
  * 如果$n=p\times q$，而且p，q互质，有$\varphi(n)=\varphi(p\times q)=\varphi(p)\times \varphi(q)$
* 欧拉定理：对任意互素的a和n，有$a^{\varphi(n)}=1\; (mod\;n)$
  * 费马小定理：$b^{p-1}=1(mod\;p)$，故$b\times b^{p-2}=1(mod\;p)$，所以b的逆元$x=b^{p-2}$

### （扩展）欧几里得

* 又称**辗转相除法**，是指用于计算两个正整数a，b的最大公约数（Greatest Common Divisor），**扩展欧几里得**除了求出最大公约数，还找出相应的x，y（其中一个很可能是负数）
  
* **贝祖等式**（贝祖定理）：是一个关于最大公约数的定理，对任何整数a，b和它们的最大公约数d，方程$ax+by=m$有整数解当且仅当m是d的倍数
  
  * 特别的：方程$ax+by=1$有整数解当且仅当整数a和b互素
  * 也就有了扩展欧几里得用来求逆元：a的逆元（模b下）是x%b （因为x可能为负数）
  * [ref: 扩展欧几里得算法详解](https://blog.csdn.net/destiny1507/article/details/81750874)
  
* ```python
   # 欧几里得
   def gcd (a, b):
       return a if b == 0 else gcd(b, a % b)
   
   # 扩展欧几里得
   def egcd ( a , b ):
       if (b == 0):
          return 1, 0, a
      else:
          x , y , q = egcd( b , a % b ) # q = GCD(a, b) = GCD(b, a%b)
          x , y = y, ( x - (a // b) * y )
          return x, y, q
    
  # 可以利用扩展欧几里得求逆元
  def mod_inv(a,b):
      return egcd(a,b)[0]%b #求a模b得逆元
  ```

* [ ] 非递归扩展欧几里得算法？[ref: 扩展欧几里得](https://blog.csdn.net/m0_37953323/article/details/79734683)

### 中国剩余定理

* [中国剩余定理算法详解(余数互质和不互质）](https://blog.csdn.net/Dafang_Xu/article/details/50818919)
* [中国剩余定理算法详解（互质与不互质情况）](https://blog.csdn.net/codeswarrior/article/details/81056425)

### 杨辉三角/Pascal Triangle

### 快速求组合数

* [ref: 如何快速求解组合数 C(n,m) 取模 【最简单的方法】](https://blog.csdn.net/qq_41357771/article/details/79896213)
* 

### RSA

* [RSA算法之实现篇（C++版）](https://blog.csdn.net/qmickecs/article/details/39676655)
* [用gmp库实现rsa加密算法](https://blog.csdn.net/qq_40129237/article/details/81286199)

### split分割字符串

* [C++ split分割字符串函数](https://www.cnblogs.com/dingxiaoqiang/p/8228390.html)

## 记忆

* [函数对象（函数符）](https://blog.csdn.net/u014709760/article/details/89323988)

  * 函数符是可以以函数方式与()结合使用的任意对象。这包括函数名、指向函数的指针和重载了()运算符的类对象。

* [C++之Lambda表达式](https://www.cnblogs.com/jimodetiantang/p/9016826.html)

* copy

* cassert

* [CPP容器-list](https://blog.csdn.net/ivalue/article/details/82752618)

* to_string

* use boost library
  
* [How to use std::pair as key to std::unordered_map in C++](https://www.techiedelight.com/use-std-pair-key-std-unordered_map-cpp/)
  
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

* lower_bound(begin, end, num) 大于等于num（指针）

* upper_bound(begin, end, num) 大于num（指针）

* pair<T1, T2>

  * pair在比较时按默认方式先比较T1, 再比较T2

* multiset 
  * lower_bound 大于等于最小
  * upper_bound 小于等于最大
  * find
  * erase
    * erase接收value或者iterator，接收value会删除所有等于value的值，接收iterator只会删除iterator指向的值
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

* bitset

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

## LINKS

* [50题（ACM学习推荐题）](https://blog.csdn.net/jiangX1994/article/details/38019519)

## ToDos

- [ ] 9.1.1 took 500ms, To Be Optimized
- [ ] 字符串匹配算法（判断是否为子串）[NOI/1.7编程基础之字符串/18:验证子串](http://noi.openjudge.cn/ch0107/18)
- [ ] setprecision为何能表示很大的pow(2, n)