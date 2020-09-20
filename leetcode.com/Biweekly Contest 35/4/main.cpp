#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  int m, n;
  bool chk(int color, vector<vector<int>> &rects, vector<vector<int>> &grid) {
    int x1 = rects[color][0];
    int y1 = rects[color][1];
    int x2 = rects[color][2];
    int y2 = rects[color][3];
    for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
        if (grid[i][j] && grid[i][j] != color) return false;
      }
    }
    for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
        grid[i][j] = 0;
      }
    }
    return true;
  }

 public:
  bool isPrintable(vector<vector<int>> &targetGrid) {
    m = targetGrid.size();
    n = targetGrid[0].size();
    // (x1, y1, x2, y2) top left & bottom right points of rects
    vector<vector<int>> rects(61, vector<int>(4));
    for (auto &rect : rects) {
      rect[0] = m;
      rect[1] = n;
      rect[2] = 0;
      rect[3] = 0;
    }
    unordered_set<int> colors;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int color = targetGrid[i][j];
        colors.insert(color);
        rects[color][0] = min(rects[color][0], i);
        rects[color][1] = min(rects[color][1], j);
        rects[color][2] = max(rects[color][2], i);
        rects[color][3] = max(rects[color][3], j);
      }
    }
    while (!colors.empty()) {
      unordered_set<int> colors2;
      for (int color : colors) {
        if (!chk(color, rects, targetGrid)) {
          colors2.insert(color);
        }
      }
      if (colors2.size() == colors.size()) return false;
      colors = colors2;
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  vector<vector<int>> grid = {{1, 1, 1}, {3, 1, 3}};
  Solution s;
  cout << s.isPrintable(grid) << endl;
  return 0;
}
