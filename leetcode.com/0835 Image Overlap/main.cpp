#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;

 public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    n = img1.size();
    vector<pair<int, int>> ones_img1, ones_img2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (img1[i][j]) ones_img1.emplace_back(i, j);
        if (img2[i][j]) ones_img2.emplace_back(i, j);
      }
    }
    if (ones_img1.size() > ones_img2.size()) {
      swap(img1, img2);
      swap(ones_img1, ones_img2);
    }
    int res = 0;
    for (int di = -n + 1; di < n; ++di) {
      for (int dj = -n + 1; dj < n; ++dj) {
        int cur = 0;
        for (auto& p : ones_img1) {
          int i = p.first + di, j = p.second + dj;
          if (i >= 0 && j >= 0 && i < n && j < n && img2[i][j]) ++cur;
        }
        res = max(res, cur);
      }
    }
    return res;
  }
};
