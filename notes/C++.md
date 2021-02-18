# C++ Notes

## C++刷题模板

* 头

```C++
// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data
```

* gcc编译的时候加上`-DDEBUG`参数即可define DEBUG，开启输出

* 更多内容可以参考我的[vscode 的cpp snippets](https://github.com/sky-bro/.dotfiles/blob/master/.config/Code/User/snippets/cpp.json)

## 常见陷阱 Pitfalls

* double间的比较要通过比较差值是否达到精度要求
* 1e3 默认是double

## 记忆

* partial_sum

* 位运算
  * b&-b可以得到最低位的1（比如2&-2=0b10）

* rotate

* queue

  * priority_queue
    * [C++ std::priority_queue uses the lambda expression](https://stackoverflow.com/questions/41053232/c-stdpriority-queue-uses-the-lambda-expression)
  
* namespace

  * unnamed/anonymous namespace
  
* tuple

  * how to hash a tuple in c++ ?
  
  * [Generic hash for tuples in unordered_map / unordered_set](https://stackoverflow.com/questions/7110301/generic-hash-for-tuples-in-unordered-map-unordered-set)

* scanf

  * ```c
    std::sscanf(str.c_str(), "%d:%[^:]:%d", &id, strbuf, &tstamp);
    ```

* array

  * 数组类是**固定大小**的序列容器

* sstream

  * TODO

* numeric

  * gcd, lcm (C++17)
  * accumulate

* next_permutation

* complex

* 正则 regex

  * [正则表达式30分钟入门教程](https://deerchao.cn/tutorials/regex/regex.htm)
    * 贪婪模式
    * 后向引用
      * 匹配重复单词：`\b(\w+)\b\s+\1\b` 或 `\b(?<Word>\w+)\b\s+\k<Word>\b`
    * 捕获
    * 零宽断言
  
* cin

  * cin.ignore
  * [cin.ignore()的用法](https://blog.csdn.net/wxbmelisky/article/details/48596881)

* using

  * [C++关键字之using的的用法总结](https://www.cnblogs.com/wangkeqin/p/9339862.html)

* random

  * [C++标准库——random](https://blog.csdn.net/u010487568/article/details/51526337?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)

* decltype

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
  * atan, atan2

* strupr(char []) not in standard c library

* strlwr(char [])

* strcat(char \* dest, char \* str)

* strchr 查找首次出现字符的位置

* strrchr

* strstr和str1.find(str2) (c++中string类型)

* atoi

* atof

* itoa (windows)

* freopen

* stricmp (..)

* binary_search 找到返回true

* lower_bound(begin, end, num) 第一个不小于num的指针

* upper_bound(begin, end, num) 第一个大于num的指针

* pair<T1, T2>

  * pair在比较时按默认方式先比较T1, 再比较T2

* multiset
  * lower_bound 大于等于最小
  * upper_bound 小于等于最大f
  * find
  * erase
    * erase接收value或者iterator，接收value会删除所有等于value的值，接收iterator只会删除iterator指向的值
  * insert
  
* set
  
  * 不能有重复元素
  
* multimap

  * equal_range

* map
  * 关键字不相等
  * 可以用[]
  
* unordered_map

  * 不用排序，比map快
  * 可能有坑，最坏复杂度是$O(n^2)$，因为可能出现collision，尤其是在codeforces上可能被别人hack。而map则固定最坏是$nlog(n)$。所以时间限制如果允许就直接用map就好了，不然可以自定义hash函数，增加点随机量，参考[neal's blog: Blowing up unordered_map, and how to stop getting hacked on it](https://codeforces.com/blog/entry/62393)

* max_element

* sort

* nth_element

  * 可用来寻找第k大

  * 原理：[ref: 标准库 之 nth_element](https://blog.csdn.net/xuqingict/article/details/25488865)

    * 如果元素个数比较多的时候，那么利用快排的partition的思想，就可以将问题的规模降低。

    * 如果元素个数比较少的时候，那么直接使用插入排序，是很好的选择， 在数组元素个数比较少或者是数字基本有序的时候，插入排

      序是很好的选择。

* partition

  * [划分(partition)算法](https://blog.csdn.net/u012604810/article/details/80838497)
  * three-way-partition

* memset

* cctype

* bitset

  * [leetcode 416: Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/Simple-C%2B%2B-4-line-solution-using-a-bitset)

  * [leetcode 461: Hamming Distance](https://leetcode.com/problems/hamming-distance)

    * ```c++
      // ref: https://leetcode.com/problems/hamming-distance/discuss/94832/C%2B%2B-one-liner
      class Solution {
      public:
          int hammingDistance(int x, int y) {
              // return __builtin_popcount(x^y);
              return bitset<32>(x^y).count();
          }
      };
      ```

* 圆周率PI怎么得

  * ```c++
    #include <cstdio>
    #include <cmath>
    int main() {
        const double pi = acos(-1.0);
        // ...
    }
    ```
