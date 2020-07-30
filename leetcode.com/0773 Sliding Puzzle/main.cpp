#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
int fac[6] = {120, 24, 6, 2, 1, 1}; // f(5), ..., f(0)

#define A(i) board[i/3][i%3]

class Solution {
private:
  int target;

  // 康托展开和逆康托展开 https://blog.csdn.net/wbin233/article/details/72998375
  int board2index(const vector<vector<int> >& board) {
    int idx = 0;
    for (int i = 0; i < 6; ++i) {
      int count_smaller = 0;
      for (int j = i + 1; j < 6; ++j) {
        if (A(j) < A(i)) ++count_smaller;
      }
      idx += fac[i] * count_smaller;
    }
    return idx;
  }

  void index2board(int idx, vector<vector<int> > & board) {
    bool used[6]{};
    for (int i = 0; i < 6; ++i) {
      int count_smaller = idx / fac[i];
      for (int j = 0; ; ++j) {
        if (used[j] == false) --count_smaller;
        if (count_smaller < 0) {
          A(i) = j;
          used[j] = true;
          break;
        }
      }
      idx %= fac[i];
    }
  }

  int bfs(vector<vector<int> > &board) {
    vector<vector<int> > target_board {
      {1, 2, 3},
      {4, 5, 0}
    };
    int target_idx = board2index(target_board);
    int cur_idx = board2index(board);
    if (target_idx == cur_idx) return 0;
    queue<int> q;
    q.push(cur_idx);
    int steps = 0;
    vector<bool> visited(6*5*4*3*2);
    while (!q.empty()) {
      ++steps;
      for (int sz = q.size(); sz; --sz) {
        int cur_idx = q.front();
        q.pop();
        index2board(cur_idx, board);
        int r = 0, c = 0;
        bool ok = false;
        for (; r < 2; ++r) {
          for (c = 0; c < 3; ++c) {
            if (board[r][c] == 0) {
              ok = true;
              break;
            }
          }
          if (ok) break;
        }
        for (int i = 0; i < 4; ++i) {
          int nr =  di[i] + r;
          int nc = dj[i] + c;
          if (nr <= 1 && nr >= 0 && nc <= 2 && nc >=0) {
            swap(board[nr][nc], board[r][c]);
            cur_idx = board2index(board);
            if (visited[cur_idx] == false) {
              if (cur_idx == target_idx) return steps;
              q.push(cur_idx);
              visited[cur_idx] = true;
            }
            swap(board[nr][nc], board[r][c]);
          }
        }
      }
    }
    return -1;
  }
public:
    int slidingPuzzle(vector<vector<int> >& board) {
        return bfs(board);
    }
};
