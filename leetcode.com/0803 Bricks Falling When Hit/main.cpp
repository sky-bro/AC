#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// ref: Python Solution by reversely adding hits bricks back
// https://leetcode.com/problems/bricks-falling-when-hit/discuss/119829/Python-Solution-by-reversely-adding-hits-bricks-back

// ref: Union-find Logical Thinking
// https://leetcode.com/problems/bricks-falling-when-hit/discuss/195781/Union-find-Logical-Thinking

// use union find

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

class Solution {
 private:
  vector<int> ids, counts;
  int n, R, C;
  int F(int x) {
    int p = x;
    while (p != ids[p]) {
      p = ids[p];
    }

    // optimization, change parent of nodes on the path to the root node
    int p2 = x;
    while (ids[p2] != p) {
      int next_p2 = ids[p2];
      ids[p2] = p;
      p2 = next_p2;
    }

    return p;
  }
  void U(int p, int q) {
    int pid = F(p), qid = F(q);
    if (pid != qid) {
      ids[qid] = pid;
      counts[pid] += counts[qid];
    }
  }

  void U_around(int i, int j, vector<vector<int>>& grid) {
    int p = i * C + j + 1;
    for (int k = 0; k < 4; ++k) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni >= 0 && ni < R && nj >= 0 && nj < C && grid[ni][nj] == 1) {
        int q = ni * C + nj + 1;
        U(p, q);
      }
    }
    if (i == 0) U(0, p);
  }

 public:
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    n = hits.size(), R = grid.size(), C = grid[0].size();

    /* mark cells to hit (=1) as 2 */
    // (0: empty cell, 1: brick, 2: brick removed, but will be added back later)
    for (auto& hit : hits)
      if (grid[hit[0]][hit[1]] == 1) grid[hit[0]][hit[1]] = 2;

    /* setup disjoint set */
    ids.clear(), counts.clear();
    ids.resize(R * C + 1);
    iota(ids.begin(), ids.end(), 0);
    counts.resize(R * C + 1, 1);

    // union neighboring brick cells
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j)
        if (grid[i][j] == 1) {
          U_around(i, j, grid);
        }
    }

    /* counts[0] also ok for my implementation of func U */
    int bricks_left = counts[F(0)];

    vector<int> res(n);
    // add bricks back
    for (int i = n - 1; i >= 0; --i) {
      auto& hit = hits[i];
      if (grid[hit[0]][hit[1]] == 2) {
        grid[hit[0]][hit[1]] = 1;  // Restore to last erasure.
        U_around(hit[0], hit[1], grid);
        int new_bricks_left = counts[F(0)];
        res[i] = max(new_bricks_left - bricks_left - 1,
                     0);  // Excluding the brick to erase.
        bricks_left = new_bricks_left;
      }
    }
    return res;
  }
};

template <typename T>
void printArr(const vector<T>& arr) {
  for (const T& t : arr) cout << t << " ";
  cout << endl;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 1, 0}};
  vector<vector<int>> hits = {{1, 0}};
  Solution s;
  printArr(s.hitBricks(grid, hits));
  return 0;
}
