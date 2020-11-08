#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;

class Solution {
 private:
  vector<LL> segment_tree;
  int n = 100001;
  int sumRange(int i, int j) {  // sum range [i, j]
    int sum = 0;
    for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
      if (i & 1) sum += segment_tree[i++];
      if (j & 1) sum += segment_tree[--j];
    }
    return sum;
  }
  void update(int i, int val) {
    i += n;
    if (segment_tree[i] == val) return;
    for (segment_tree[i] = val; i > 1; i >>= 1) {
      segment_tree[i >> 1] = segment_tree[i] + segment_tree[i ^ 1];
    }
  }

 public:
  int createSortedArray(vector<int>& instructions) {
    LL res = 0;
    segment_tree.clear();
    segment_tree.resize(2 * n);
    // for (int num : instructions) {
    //   segment_tree[num + n]++;
    // }
    // for (int i = n - 1; i > 0; --i) {
    //   segment_tree[i] = segment_tree[i << 1] + segment_tree[i << 1 | 1];
    // }
    for (int num : instructions) {
      update(num, segment_tree[num + n] + 1);
      if (num == 0 || num == n - 1) {
        continue;
      }
      res = (res + min(sumRange(0, num - 1), sumRange(num + 1, n - 1))) % MOD;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> ins = {1, 5, 6, 2};
  ins = {4, 14, 10, 2, 5, 3, 8, 19, 7, 20, 12, 1, 9, 15, 13, 11, 18, 6, 16, 17};
  cout << s.createSortedArray(ins) << endl;
  return 0;
}
