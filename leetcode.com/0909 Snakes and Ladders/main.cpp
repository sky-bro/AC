#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// bfs
class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
#define A(x)                 \
  board[n - 1 - (x - 1) / n] \
       [(((x - 1) / n) & 1) ? (n - 1 - (x - 1) % n) : (x - 1) % n]
    int n = board.size();
    queue<int> q;
    q.push(1);
    vector<bool> vis(n * n + 1);
    vis[1] = true;
    int res = 0;
    while (!q.empty()) {
      ++res;
      for (int sz = q.size(); sz; --sz) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i < 7; ++i) {
          int nxt = cur + i;
          if (nxt > n * n) break;
          int x = A(nxt);
          if (x != -1) nxt = x;
          if (vis[nxt]) continue;
          vis[nxt] = true;
          if (nxt == n * n) return res;
          q.push(nxt);
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> arr = {{-1, -1, -1}, {-1, 9, 8}, {-1, 8, 9}};
  arr = {{-1, -1, -1, 46, 47, -1, -1, -1}, {51, -1, -1, 63, -1, 31, 21, -1},
         {-1, -1, 26, -1, -1, 38, -1, -1}, {-1, -1, 11, -1, 14, 23, 56, 57},
         {11, -1, -1, -1, 49, 36, -1, 48}, {-1, -1, -1, 33, 56, -1, 57, 21},
         {-1, -1, -1, -1, -1, -1, 2, -1},  {-1, -1, -1, 8, 3, -1, 6, 56}}; // 4
  cout << s.snakesAndLadders(arr) << endl;
  return 0;
}
