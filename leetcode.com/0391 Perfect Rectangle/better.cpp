#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// ref: Really Easy Understanding Solution(O(n), Java)
// https://leetcode.com/problems/perfect-rectangle/discuss/87181/Really-Easy-Understanding-Solution(O(n)-Java)
class Solution {
 private:
  inline string getKey(int x, int y) {
    return to_string(x) + " " + to_string(y);
  }

 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    if (rectangles.empty() || rectangles[0].empty()) return false;
    int x1 = INT32_MAX, y1 = INT32_MAX, x2 = INT32_MIN, y2 = INT32_MIN,
        area = 0;
    unordered_set<string> s;
    for (auto v : rectangles) {
      x1 = min(x1, v[0]);
      y1 = min(y1, v[1]);
      x2 = max(x2, v[2]);
      y2 = max(y2, v[3]);
      area += (v[2] - v[0]) * (v[3] - v[1]);
      string a = getKey(v[0], v[1]), b = getKey(v[0], v[3]),
             c = getKey(v[2], v[1]), d = getKey(v[2], v[3]);
      if (!s.erase(a)) s.insert(a);
      if (!s.erase(b)) s.insert(b);
      if (!s.erase(c)) s.insert(c);
      if (!s.erase(d)) s.insert(d);
    }
    return s.count(getKey(x1, y1)) && s.count(getKey(x1, y2)) &&
           s.count(getKey(x2, y1)) && s.count(getKey(x2, y2)) &&
           s.size() == 4 && area == (x2 - x1) * (y2 - y1);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;

  vector<vector<int>> rectangles = {{1, 1, 3, 3},
                                    {3, 1, 4, 2},
                                    {3, 2, 4, 4},
                                    {1, 3, 2, 4},
                                    {2, 3, 3, 4}};  // true
  rectangles = {{0, 0, 4, 1}, {7, 0, 8, 2}, {6, 2, 8, 3},
                {5, 1, 6, 3}, {4, 0, 5, 1}, {6, 0, 7, 2},
                {4, 2, 5, 3}, {2, 1, 4, 3}, {0, 1, 2, 2},
                {0, 2, 2, 3}, {4, 1, 5, 2}, {5, 0, 6, 1}};  // true
  cout << s.isRectangleCover(rectangles) << endl;
  return 0;
}
