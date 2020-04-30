#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

static vector<int> m = [](){
  vector<int> mp('G'+1);
  for (int i = 0; i < 7; ++i) {
    mp['A'+i] = 1 << i;
  }
  return mp;
}();

class Solution {
private:
  unordered_map<int, vector<int>> a;
  vector<int> b;
  bool dfs(int i, int n) {
    if (i == n-1) {i = 0; --n;}
    if (n == 1) return true;
    int bak = b[i];
    int idx = b[i]<<7 | b[i+1];
    for (int num: a[idx]) {
      b[i] = num;
      if (dfs(i+1, n)) return true;
    }
    b[i] = bak;
    return false;
  }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        b.resize(n);
        for (int i = 0; i < n; ++i) b[i] = m[bottom[i]];
        for (const string& al: allowed) a[m[al[0]] << 7 | m[al[1]]].emplace_back(m[al[2]]);
        return dfs(0, n);
    }
};
