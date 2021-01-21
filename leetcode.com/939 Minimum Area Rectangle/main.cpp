#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minAreaRect(vector<vector<int>> &points) {
    unordered_map<int, unordered_set<int>> r2c, c2r;
    int res = INT32_MAX;
    for (auto &v : points) {
      r2c[v[0]].insert(v[1]);
      c2r[v[1]].insert(v[0]);
    }
    if (r2c.size() == 1 || c2r.size() == 1) return 0;
    for (auto it1 = r2c.begin(), it2 = next(it1); it2 != r2c.end();
         ++it1, it2 = next(it1)) {
      for (; it2 != r2c.end(); ++it2) {
        set<int> st;
        for (int c : it1->second) {
          if (it2->second.count(c)) st.insert(c);
        }
        if (st.size() <= 1) continue;
        int a = abs(it1->first - it2->first), b = 40000;
        for (auto it3 = st.begin(), it4 = next(it3); it4 != st.end();
             ++it3, ++it4) {
          b = min(b, (*it4) - (*it3));
        }
        res = min(res, a * b);
      }
    }
    return res == INT32_MAX ? 0 : res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> points = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
  cout << s.minAreaRect(points) << endl;
  return 0;
}
