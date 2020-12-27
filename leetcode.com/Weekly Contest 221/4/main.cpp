#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

clock_t starttime, endtime;
class Node {
public:
  Node *l, *r;
  Node(Node *l = nullptr, Node *r = nullptr) : l(l), r(r) {}
  ~Node() {
    delete l;
    delete r;
  }
  void insert(int num) {
    Node *p = this;
    for (int i = 29; i >= 0; --i) {
      if (num & (1 << i)) {
        if (!p->r)
          p->r = new Node();
        p = p->r;
      } else {
        if (!p->l)
          p->l = new Node();
        p = p->l;
      }
    }
  }
};

class Solution {
public:
  vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    starttime = clock();
    int n = queries.size(), m = nums.size();
    sort(nums.begin(), nums.end());
    vector<array<int, 3>> qq(n);
    for (int i = 0; i < n; ++i)
      qq[i] = {queries[i][1], queries[i][0], i};
    sort(qq.begin(), qq.end());
    vector<int> res(n, -1);
    Node *root = new Node();
    int I = 0;
    for (int i = 0; i < n; ++i) { //
      auto &v = qq[i];
      while (I < m && nums[I] <= v[0]) { // O(31m)
        root->insert(nums[I]);
        ++I;
      }
      if (!I)
        continue;
      int mx = 0;
      Node *p = root;
      for (int i = 29; i >= 0; --i) {
        if (v[1] & (1 << i)) {
          if (p->l) {
            mx |= (1 << i);
            p = p->l;
          } else {
            p = p->r;
          }
        } else {
          if (p->r) {
            mx |= (1 << i);
            p = p->r;
          } else {
            p = p->l;
          }
        }
      }
      res[v[2]] = mx;
    }
    endtime = clock();
    cout << "took: " << (double)(endtime - starttime) / CLOCKS_PER_SEC << endl;
    return res;
  }
};

template <typename T> void printArr(const vector<T> &arr) {
  for (const T &t : arr)
    cout << t << " ";
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  vector<int> nums = {0, 1, 2, 3, 4};
  vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
  nums = {5, 2, 4, 6, 6, 3};
  queries = {{12, 4}, {8, 1}, {6, 3}};
  Solution s;
  auto v = s.maximizeXor(nums, queries);
  printArr(v);
  return 0;
}
