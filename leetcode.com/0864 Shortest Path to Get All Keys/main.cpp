#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

class Solution {
 public:
  int shortestPathAllKeys(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size();
    int x0, y0;
    int key_mask = 0;
    for (int i = 0; i < m; ++i) {
      bool found = false;
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '@') {
          x0 = i;
          y0 = j;
        } else if (grid[i][j] >= 'a') {
          ++key_mask;
        }
      }
    }
    key_mask = (1 << key_mask) - 1;

    int d = 0;
    grid[x0][y0] = '.';
    queue<array<int, 3>> q;
    array<int, 3> p{x0, y0, 0};  // i, j, key
    q.push(p);
    set<array<int, 3>> vis;
    vis.insert(p);
    while (!q.empty()) {
      ++d;
      for (int sz = q.size(); sz; --sz) {
        auto p = q.front();
        q.pop();
        int i = p[0], j = p[1], keys = p[2];
        for (int k = 0; k < 4; ++k) {
          // int ni = i + di[k], nj = j + dj[k];
          p[0] = i + di[k];
          p[1] = j + dj[k];
          if (p[0] >= 0 && p[0] < m && p[1] >= 0 && p[1] < n &&
              grid[p[0]][p[1]] != '#' && vis.find(p) == vis.end()) {
            if (grid[p[0]][p[1]] == '.') {
              vis.insert(p);
              q.push(p);
            } else if (grid[p[0]][p[1]] >= 'a') {
              p[2] = keys | (1 << (grid[p[0]][p[1]] - 'a'));
              if (p[2] == key_mask) return d;
              if (vis.find(p) == vis.end()) {
                vis.insert(p);
                q.push(p);
              }
              p[2] = keys;
            } else {
              if (keys & (1 << (grid[p[0]][p[1]] - 'A'))) {
                vis.insert(p);
                q.push(p);
              }
            }
          }
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> grid = {"Dd#b@", ".fE.e", "##.B.", "#.cA.", "aF.#C"};
  grid = {".##..##...",
          "...#.#.#B#",
          ".#.#......",
          ".#....#...",
          "...###...C",
          "#.##..#.#.",
          "...A.c....",
          "#..a.@..##",
          "##..#.....",
          "..#....b.."};
  cout << s.shortestPathAllKeys(grid) << endl;
  return 0;
}
