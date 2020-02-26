#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  unordered_map<int, unordered_set<int>> cantCross;
  bool dfs(vector<int>& stones, int idx, int k) {
    if (idx == n - 1) return true;
    if (cantCross[idx].count(k) != 0) return false;
    auto it = stones.begin() + idx;
    // next jump: k-1
    if (k != 1) {
      it = lower_bound(it, stones.end(), k - 1 + stones[idx]);
      if (it == stones.end()) {
        cantCross[idx].insert(k);
        return false;
      }
      if (*it == k - 1 + stones[idx]) {
        bool res = dfs(stones, it - stones.begin(), k - 1);
        if (res) return true;
        ++it;
      }
    } else {
      // jump 0, still here
      ++it;
    }
    // next jump: k
    if (it == stones.end()) {
      cantCross[idx].insert(k);
      return false;
    }
    if (*it == k + stones[idx]) {
      bool res = dfs(stones, it - stones.begin(), k);
      if (res) return true;
      ++it;
    }
    // next jump: k+1
    if (it == stones.end()) {
      cantCross[idx].insert(k);
      return false;
    }
    if (*it == k + 1 + stones[idx]) {
      bool res = dfs(stones, it - stones.begin(), k + 1);
      if (res) return true;
    }
    cantCross[idx].insert(k);
    return false;
  }

 public:
  bool canCross(vector<int>& stones) {
    n = stones.size();
    if (stones[1] != 1) return false;
    return dfs(stones, 1, 1);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> stones = {0, 1, 3, 4, 5, 7, 9, 10, 12};
  cout << s.canCross(stones) << endl;
  return 0;
}
