# My Coding Practice

## Current

* [ ] I'm trying to finish all [leetcode](https://leetcode.com/sky_io/) (algorithm) problems the first time. (do it in the order of problem ID)
* [ ] After that I'll review my code again by category, write/organize my documents.
* [ ] google kickstart

## 算法&数据结构 Algorithms & Data Structures

### Binary Search

* [find the kth smallest element in the (sorted) matrix](https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378)
  * biselect
    * TODO
* median of medians

### Graph 图

* BFS
  * two way BFS
* DFS
* Dijkstra's Algorithm
  * heap + bfs / A*
* Bellman Ford
  * dp
* Bipartite graph/network 二分图
  * 匹配,最大匹配 (maximal matching problem),完全匹配/完备匹配
    * 增广路径: 若P是图G中一条连通两个未匹配顶点的路径，并且属M的边和不属M的边（即已匹配和待匹配的边）在P上交替出现，则称P为相对于M的一条增广路径
      * P的路径长度必为奇数,第一条和最后一条边都不属于M
      * P经过取反操作可以得到一个更大的匹配M'
      * M为G的最大匹配当且仅当不存在相对于M的增广路径
    * 利用增广路径求**最大匹配**(匈牙利算法 Hungary: 求无边权二分图的最大匹配) TODO
    * KM算法：带权二分图的最大权完美匹配 TODO
  * leetcode 0886: 就是判断是不是二分图
    * 用染色法解决
* 网络流算法

### Coordinate Compression 坐标压缩

* ref: [leetcode solution: 699 Falling Squares](https://leetcode.com/articles/falling-squares/)

* ```python
  coords = set()
  for left, size in positions:
      coords.add(left)
      coords.add(left + size - 1)
  index = {x: i for i, x in enumerate(sorted(coords))}
  # position: [(100,100), (200,100)]
  # index = {100: 0, 199: 1, 200: 2, 299: 3}
  ```

### 割点，桥

* TODO

### A*

* TODO

### Maze router

* [wiki: routing](https://en.wikipedia.org/wiki/Routing_(electronic_design_automation))
* [Maze routing & channel routing](http://users.eecs.northwestern.edu/~haizhou/357/lec6.pdf)

#### Lee Algorithm

#### Hadlock (实际上是A*算法的一个实例)

* used in computing shortest distance/path in a grid from S to T
* faster than bfs, use dequeue (double ended queue), each node stores an extra `detour_count` value (while bfs just needs node's row and column value)
* the wanted shortest distance (if found: cur_node == T) is `hamming distance + 2*detour_count`, when we move closer to T, `detour_count` remains same as last node, push this `next_node` to dequeue from one side (we get `cur_node` also from this side); when we move further from T, `detour_count` increases by 1, and we push this `next_node` to dequeue from the other side of dequeue. (basically same as bfs, just uses a dequeue)
* related problems: [leetcode 0675: Cut Off Trees for Golf Event](https://leetcode.com/problems/cut-off-trees-for-golf-event/), code on github

### Find Prime Numbers

#### Sieve of Eratosthenes

* [wiki](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)

  * ```pseudocode
    algorithm Sieve of Eratosthenes is
        input: an integer n > 1.
        output: all prime numbers from 2 through n.

        let A be an array of Boolean values, indexed by integers 2 to n,
        initially all set to true.

        for i = 2, 3, 4, ..., not exceeding √n do
            if A[i] is true
                for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
                    A[j] := false

        return all i such that A[i] is true.
    ```

#### Segmented Sieve

### Ring Buffer

* TODO

### 正则Regex

* [正则表达式30分钟入门教程](https://deerchao.cn/tutorials/regex/regex.htm)

* related problems
  * [leetcode: 591. Tag Validator](https://leetcode.com/problems/tag-validator/)

### 凸包 Convex hull

* [Convex hull & different algorithms](http://www.csie.ntnu.edu.tw/~u91029/ConvexHull.html)
  * Graham's Scan
  * Andrew's Monotone Chain (better I think)
* [wiki](https://en.wikipedia.org/wiki/Convex_hull_algorithms)
* related problems:
  * [leetcode: 587. Erect the Fence](https://leetcode.com/problems/erect-the-fence/)

### Merkle Tree

* [Merkle Hashing Tree](https://www.jianshu.com/p/819e8fd10938)

### 2-SAT

* TODO
* [2-sat算法]([http://laughingtree.cn/2019/11/09/2-sat%E7%AE%97%E6%B3%95/](http://laughingtree.cn/2019/11/09/2-sat算法/))

### 背包

* TODO
* [经典背包问题 01背包+完全背包+多重背包](https://blog.csdn.net/byn12345/article/details/81367392)
  * 二进制分解（多重背包）

### 排列

#### next_permutation

* ```c++
  bool nextPermutation(string& nums) {
    if (nums.empty()) return false;
    int i = nums.size() - 1;
    while (i >= 1 && nums[i] <= nums[i - 1]) i--;
    if (i == 0) return false;  // no next permutation, i.e. already largest
  
    int j = nums.size() - 1;
    while (nums[j] <= nums[i - 1]) j--;
    swap(nums[i - 1], nums[j]);
  
    reverse(nums.begin() + i, nums.end());
    return true;
  }
  ```

* related problems:

  * [leetcode: 31. Next Permutation](https://leetcode.com/problems/next-permutation/)
  * [leetcode: 556. Next Greater Element III](https://leetcode.com/problems/next-greater-element-iii/)

#### prev_permutation

### 组合

#### 快速求组合数

* 法1: [ref: 如何快速求解组合数 C(n,m) 取模 【最简单的方法】](https://blog.csdn.net/qq_41357771/article/details/79896213)

* 法2: 适合大组合数 / 大数处理 (更好，更简单，更快)， ~~但不精确~~ 整数能有多不精确

> 核心就是 取对数进行运算，乘除法转为加减法

对于$C(n, k) = (n!)/((n-k)!)/(k!)$

等价于(这里用浮点数，可能会有精度损失): $C(n, k) = exp(log(C(n, k))) = exp(log(n!)-log((n-k)!)-log(k!))$

如果结果特别大时，一般题目会让你继续用这个数和另外一个很小的数相乘(另外的这个数也用相同底的对数形式表示即可)，所以继续用对数保存(暂时不要算$exp()$); 如果直接需要这个整数结果可以将结果取整$int(x+0.5)$

所以只需要提前算好$log(n!)$就好了，$log(n!)=log(1)+log(2)+...+log(n)$

相关题目：[google kickstart round B, 4](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d8565)

### Random / Sampling

* Reservoir sampling

### Stack-sortable permutation

* [wiki](https://en.wikipedia.org/wiki/Stack-sortable_permutation)

### SkipLists 跳跃表

* [跳表（skiplist）的理解](https://blog.csdn.net/weixin_41462047/article/details/81253106)

### Union Find

* [有一种算法叫做“Union-Find”？](https://www.cnblogs.com/SeaSky0606/p/4752941.html) (原文有错--博主知道了，但好像还没改。。。见第一条评论`id[q]=pID;//这里应该改为id[qID]=pID;`)
* related problems
  * [leetcode 399: [Java] Union find and DFS](https://leetcode.com/problems/evaluate-division/discuss/278276/Java-Union-find-and-DFS)
  * [leetcode 684: Redundant Connection](https://leetcode.com/problems/redundant-connection/)
  * [leetcode 685: Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/)
  * [leetcode 721: Accounts Merge](https://leetcode.com/problems/accounts-merge/)

### Kadane's Algorithm

* ref: [Kadane's Algorithm](https://www.jianshu.com/p/89939a9dc3e1)

* O(n)时间计算求最大的子数组元素和
* [leetcode: 121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* 拓展：同样求子数组最大元素和，但外加限制和小于k，[O(nlog(n))时间解法](https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k)
  * [leetcode: 363. Max Sum of Rectangle No Larger Than K](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/): [sol](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references)

### Cache

#### Cache替换策略

##### Rand

##### FIFO: 不合适

##### LRU: 挺好

* 最近用到的数据被重用的`概率`比最早用到的数据大的多

##### LFU

### 字符串匹配

#### AC

#### KMP

* 最大前缀后缀公共元素长度（实际上是dp问题）

  * ```c++
    // D A B C D A B D E
    // 0 0 0 0 1 2 3 1 0
    int main() {
        string s = "DABCDABDE";
        int n = s.length();
        // int len = 0;
        // int i = 1; // 从第二个字符开始
        vector<int> tr(n);
        for (int len = 0, i = 1; i < n;) {
            if (s[i] == s[len]) tr[i++] = ++len;
            else if (len == 0) tr[i++] = 0;
            else len = tr[len-1];
        }
    }
    ```

* 匹配过程

  * ```c++
    int main() {
        string s1 = "ABAABABAC"
        string s2 = "BABAC"; // ABAA(BABAC)
        int n1 = s1.length(), n2 = s2.length();
        vector<int> tr(n2);
        for (int len = 0, i = 1; i < n2;) {
            if (s2[i] == s2[len]) tr[i++] = ++len;
            else if (len == 0) tr[i++] = 0;
            else len = tr[len-1];
        }
        // B A B A C
        // 0 0 1 2 0
        for (int i = 0, j = 0; i < n1; ) { // i never decreases
            while (j < n2 && s1[i] == s2[j]) {
                ++i;
                ++j;
            }
            if (j == n2) {
                // found a match

                // match start at
                // cout << i - j << endl;
                // return 0;

                // or continue matching more
                // TODO ...
                // i may decrease ? change tr ?
                // ...
            }

            // not found
            if (j == 0) ++i;
            else j = tr[j-1];
        }

    }
    ```

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

### 排序 Sort

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

#### 拓扑排序 Topological Sort

* [Kahn’s algorithm, track indegree of nodes](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/)
* [dfs + stack](https://www.geeksforgeeks.org/topological-sorting/)
* [All Topological Sorts](https://www.geeksforgeeks.org/all-topological-sorts-of-a-directed-acyclic-graph/)

#### [leetcode: Wiggle Sort 2](https://leetcode.com/problems/wiggle-sort-ii/)

* virtual indexing, partition: [leetcode discuss](https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing)

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
* related problems:
  * [leetcode: 565. Array Nesting](https://leetcode.com/problems/array-nesting/)

### 二叉树

* 完全二叉树：若设二叉树的深度为h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数(即1~h-1层为一个满二叉树)，第 h 层所有的结点都连续集中在最左边
* 满二叉树：高度为h，由2^h-1个节点构成的二叉树称为满二叉树。
* [Preorder, Inorder, and Postorder Iteratively Summarization](https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization)

#### 中序遍历

* 相当于从左到右遍历，对于二叉搜索树BST，就是从小到大遍历
* [二叉树的中序遍历非递归算法](https://blog.csdn.net/billy1900/article/details/86229656)

#### 后序遍历

* [二叉树非递归后序遍历](https://blog.csdn.net/qq_35812205/article/details/96476519)
  * 由于镜像二叉树的先序遍历=原二叉树后序遍历，可以先求出镜像先序，最后reverse一下即可。

### Hash

#### Rolling hash

#### 利用质数的乘积作为hash key

* 相关题目：[LeetCode: 49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)

### [康托展开和逆康托展开](https://blog.csdn.net/wbin233/article/details/72998375)

### LCS (longest common sequence)

### LIS (longest increasing sequence)

### 树状数组 Binary Indexed Tree (BIT) / Fenwick Tree

```c++
int n;
vector<int> A;

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

int sum(int i) {  // A[1] + A[2] + ... + A[i]
  int res = 0;
  while (i) res += A[i], i -= i & -i;
  return res;
}

void add(int i, int k) {  // adds k to A[i]
  while (i <= n) A[i] += k, i += i & -i;
}

int main(int argc, char const *argv[]) {
  cout << "input the number of elements to be added, n: ";
  cin >> n;
  A.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[0];
    add(i, A[0]);
  }
//   printArr(A);
  while (1) {
    cout << "get sum of first x elements, x: ";
    int x;
    cin >> x;
    if (x > 0 && x <= n)
      cout << "sum of first " << x << " elements is " << sum(x) << endl;
    else
      break;
  }
  return 0;
}
```

* [关于线段树(Segment tree)和树状数组(BIT)的区别？](https://www.zhihu.com/question/54746883?sort=created)
* [wiki: Fenwick tree](https://en.wikipedia.org/wiki/Fenwick_tree)

### 线段树 Segment Tree

* Segment Tree w/ Lazy Propagation (TODO)
* [Segment Tree (Iterative)](https://sky-bro.github.io/en/posts/segment-tree-iterative/)
* [Segment tree Theory and applications](http://maratona.ic.unicamp.br/MaratonaVerao2016/material/segment_tree_lecture.pdf)
* [A Recursive approach to Segment Trees, Range Sum Queries & Lazy Propagation](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/)
* [线段树（segment tree），看这一篇就够了](https://www.jianshu.com/p/6fd130084a43)
* [线段树小结](https://blog.csdn.net/lwt36/article/details/50255129)

### Li-Chao Segment Tree

* [【博客】李超线段树初步](https://ac.nowcoder.com/discuss/180365)
* [李超线段树 (Li-Chao Segment Tree)](https://www.cnblogs.com/JHSeng/p/10896570.html)

### dominator tree

### Palindromic Tree

* [Palindromic tree: behind the scenes](https://codeforces.com/blog/entry/13959)
* [回文串问题的克星——Palindrome Tree（回文树）/Palindrome Automaton（回文自动机）学习小记](https://blog.csdn.net/qq_36551189/article/details/79245675)

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

### 模运算

* `a/(b*c) % p = a * b^-1 * c^-1`

### bit manipulation

* `x&(-x)`计算第一个非0位对应的权值(如`2&(-2)=2`, `7&(-7)=1`, `6&(-6)=2`)
* `x = a ^ (a << 13)`/`x = a ^ (a >> 13)`，知道x求a的值，`a, x`都是64位无符号整数

```c++
#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;
ull e(ull a1) {
  ull a = a1 ^ (a1 << 7), b = a ^ ((a) >> 11), c = b ^ ((b) << 31);
  return c ^ ((c) >> 13);
}

// most left part not changed: a ^ (a >> 13)
// most right part not changed: a ^ (a << 13)
ull f(ull x, int len, bool left) {
  ull mask;
  if (left) {
    mask = ((1ull << len) - 1) << (64 - len);
    for (int i = len; i < 64; i += len) {
      ull m = mask >> i;
      x = (x & (~m)) | (m & ((x >> len) ^ x));
    }
  } else {
    mask = (1ull << len) - 1;
    for (int i = len; i < 64; i += len) {
      ull m = mask << i;
      x = (x & (~m)) | (m & ((x << len) ^ x));
    }
  }
  return x;
}

ull d(ull res) {
  res = f(res, 13, true);
  res = f(res, 31, false);
  res = f(res, 11, true);
  res = f(res, 7, false);
  return res;
}

int main(int argc, char const *argv[]) {
  ull x;
  cin >> x;
  cout << x << endl;
  ull y = x ^ (x >> 13);
  cout << y << endl;
  cout << f(y, 13, true) << endl;
  //   cout << e(x) << endl;
  //   cout << d(e(x)) << endl;
  return 0;
}
```

### 距离概念 Distance

* 曼哈顿距离 Manhattan Distance

在欧几里德空间的固定直角坐标系上两点所形成的线段对轴产生的投影的距离总和。
例如在平面上，坐标(x1,y1)的i点与坐标(x2,y2)的j点的曼哈顿距离为: `d(i,j)=|X1-X2|+|Y1-Y2|`

* 欧式距离 Euclidean Distance

指在m维空间中两个点之间的真实距离，或者向量的自然长度（即该点到原点的距离）。在二维和三维空间中的欧氏距离就是两点之间的实际距离。
如在二维空间，`d(i,j)=sqrt((X1-X2)^2+(Y1-Y2)^2)`

### 区间，矩形 overlap

* [leetcode: 836. Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)

```c++
// for 1D:
// left1 < right2 && left2 < right1

// for 2D:
// overlap on both x and y
```

### 点积 叉积

### 点到直线距离

### 三角形面积

根据三点坐标求面积
$S=\frac{1}{2} \times (x_1\times y_2 + x_2 \times y_3 + x_3 \times y_1 - x_1 \times y_3 - x_2 \times y_1 - x_3 \times y_2)$
`S=(1/2)*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)`

### Prime Factorization 质因数分解

* TODO

### Fermat's Theorem

* [wiki: Fermat's Last Theorem](https://en.wikipedia.org/wiki/Fermat's_Last_Theorem)

* [wiki: Fermat's theorem on sums of two squares](https://en.wikipedia.org/wiki/Fermat's_theorem_on_sums_of_two_squares)

### 牛顿法 Newton's method

* 求x的平方根 `z -= (z*z - x) / (2*z)` 直到不怎么改变
* [如何通俗易懂地讲解牛顿迭代法？](<https://blog.csdn.net/ccnt_2012/article/details/81837154>)

### 欧拉定理

* 欧拉函数$\varphi(n)\;(n \in N^*)$：小于等于n的正整数中与n互质的数的个数（如$\varphi(3)=2$）
  * $\varphi(1)=1$
  * 因为质数与小于它的每一个正整数都互质，所以如果n是质数，则$\varphi(n)=n-1$
  * 如果$n=p^k\;(p为质数,k\in N^*)$ ，则$\varphi(p^k)=p^k-p^{k-1}$
  * 如果$n=p\times q$，而且p，q互质，有$\varphi(n)=\varphi(p\times q)=\varphi(p)\times \varphi(q)$
* 欧拉定理：对任意互素的a和n，有$a^{\varphi(n)}=1\; (mod\;n)$
  * 费马小定理：$b^{p-1}=1(mod\;p)$，故$b\times b^{p-2}=1(mod\;p)$，所以b的逆元$x=b^{p-2}$

### （扩展）欧几里得

* 又称**辗转相除法**，是指用于计算两个正整数a，b的最大公约数 (GCD, Greatest Common Divisor)，**扩展欧几里得**除了求出最大公约数，还找出相应的x，y（其中一个很可能是负数）
  
  * 有了最大公约数，求最小共倍数 (LCM, Least Common Multiple)就是: `a * b / gcd(a, b)`
  
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

### 求逆元

拓展欧几里得，费马小定理(欧拉定理特例)，线性法

* [【同余定理+逆元】知识点讲解](https://blog.csdn.net/LOOKQAQ/article/details/81282342)

### 杨辉三角/Pascal Triangle

* TODO

### RSA

* [RSA算法之实现篇（C++版）](https://blog.csdn.net/qmickecs/article/details/39676655)
* [用gmp库实现rsa加密算法](https://blog.csdn.net/qq_40129237/article/details/81286199)

### split分割字符串

* [C++ split分割字符串函数](https://www.cnblogs.com/dingxiaoqiang/p/8228390.html)

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

---

* double间的比较要通过比较差值是否达到精度要求
* 1e3 默认是double

## LINKS

### algo / tutorial

* [topcoder: Competitive Programming Tutorials](https://www.topcoder.com/community/competitive-programming/tutorials/)
* [E-Maxx Algorithms in English](https://cp-algorithms.com/)
* [web.ntnu.edu.tw/~algo](http://web.ntnu.edu.tw/~algo/)
* [labuladong 的算法教程](https://labuladong.gitbook.io/algo/)

### template

* [Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook](https://github.com/Jinkela-Xiao-Zuan-Feng-Mountaineer/Codebook)

### problems

* [50题（ACM学习推荐题）](https://blog.csdn.net/jiangX1994/article/details/38019519)
* [AcWing在线题库](https://www.acwing.com/problem/)

### my profiles

* [codeforces](https://codeforces.com/profile/sky_io)
* [leetcode](https://leetcode.com/sky_io)

## ToDos

* [ ] 9.1.1 took 500ms, To Be Optimized
* [ ] 字符串匹配算法（判断是否为子串）[NOI/1.7编程基础之字符串/18:验证子串](http://noi.openjudge.cn/ch0107/18)
* [ ] setprecision为何能表示很大的pow(2, n)
