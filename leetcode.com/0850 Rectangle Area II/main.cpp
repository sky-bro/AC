#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;

class Solution {
 private:
  multiset<pair<int, int>> row;
  ll get_len() {
    int l = 0;
    ll res = 0;
    for (auto &p : row) {
      if (p.second <= l) continue;
      l = max(l, p.first);
      res += p.second - l;
      l = p.second;
    }
    return res;
  }

 public:
  int rectangleArea(vector<vector<int>> &rectangles) {
    row.clear();
    ll w = 0;
    ll y = 0;
    ll res = 0;
    map<int, multiset<pair<int, int>>> rows;
    for (auto &v : rectangles) {
      rows[v[1]].insert(make_pair(v[0], v[2]));
      rows[v[3]].insert(make_pair(-v[0], -v[2]));
    }
    for (auto &p : rows) {
      ll h = p.first - y;
      y = p.first;
      res += w * h;
      res %= MOD;
      for (auto pp : p.second) {
        if (pp.second < 0) {
          // remove this interval
          pp.first *= -1;
          pp.second *= -1;
          row.erase(row.find(pp));
        } else {
          // add this interval
          row.insert(pp);
        }
      }
      w = get_len();
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> rects = {{0, 0, 2, 2}, {1, 0, 2, 3}, {1, 0, 3, 1}};
  rects = {{11, 4, 22, 74},   {11, 33, 22, 85}, {28, 12, 59, 15},
           {61, 38, 100, 41}, {27, 27, 93, 93}, {18, 32, 80, 43}};  // 5416
  cout << s.rectangleArea(rects) << endl;
  return 0;
}
