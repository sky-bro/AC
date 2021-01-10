#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 private:
  int n;
  vector<int> ids;
  vector<int> sz;
  void U(int p, int q) {
    int pid = F(p), qid = F(q);
    if (pid != qid) {
      ids[qid] = pid;
    }
  }
  int F(int x) {
    int p = x;
    while (p != ids[p]) {
      p = ids[p];
    }

    while (ids[x] != p) {
      int t = ids[x];
      ids[x] = p;
      x = t;
    }

    return p;
  }

 public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target,
                             vector<vector<int>>& allowedSwaps) {
    n = source.size();
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
    sz.resize(n);
    fill(sz.begin(), sz.end(), 1);
    for (auto& v : allowedSwaps) {
      U(v[0], v[1]);
    }
    // vector<int> no_sort;
    unordered_map<int, pair<unordered_multiset<int>, unordered_multiset<int>>>
        yes_sort;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int id = F(i);
      yes_sort[id].first.insert(source[i]);
      yes_sort[id].second.insert(target[i]);
    }
    for (auto& p : yes_sort) {
      for (auto it1 = p.second.first.begin(); it1 != p.second.first.end();
           ++it1) {
        auto it2 = p.second.second.find(*it1);
        if (it2 == p.second.second.end())
          ++res;
        else
          p.second.second.erase(it2);
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> A = {1, 2, 3, 4};
  vector<int> B = {2, 1, 4, 5};
  vector<vector<int>> C = {{0, 1}, {2, 3}};
  Solution s;
  cout << s.minimumHammingDistance(A, B, C) << endl;
  return 0;
}
