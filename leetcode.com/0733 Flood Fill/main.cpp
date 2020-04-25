#include <iostream>
#include <vector>

using namespace std;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

class Solution {
private:
  int c0, m, n;
  void dfs(vector<vector<int>>& img, int i, int j, int c) {
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni < m && nj >= 0 && nj < n && img[ni][nj] == c0) {
        dfs(img, ni, nj, img[ni][nj] = c);
      }
    }
  }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        c0 = image[sr][sc];
        m = image.size();
        n = image[0].size();
        if (c0 == newColor) return image;
        image[sr][sc] = newColor;
        dfs(image, sr, sc, newColor);
        return image;
    }
};
