#include <iostream>
#include <vector>

using namespace std;

// ref: [C++/Java/Python] Solution with Explanation
// https://leetcode.com/problems/transform-to-chessboard/discuss/114847/C%2B%2BJavaPython-Solution-with-Explanation

class Solution {
 public:
  int movesToChessboard(vector<vector<int>>& board) {
    int N = board.size();
    int r_cnt = 0, c_cnt = 0, r_swap = 0, c_swap = 0;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) {
        if (board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j]) return -1;
      }
    for (int i = 0; i < N; ++i) {
      r_cnt += board[0][i];
      c_cnt += board[i][0];
      r_swap += board[i][0] == (i & 1);
      c_swap += board[0][i] == (i & 1);
    }
    if (r_cnt != N / 2 && r_cnt != (N + 1) / 2) return -1;
    if (c_cnt != N / 2 && c_cnt != (N + 1) / 2) return -1;
    if (N & 1) {
      if (c_swap & 1) c_swap = N - c_swap;
      if (r_swap & 1) r_swap = N - r_swap;
    } else {
      c_swap = min(N - c_swap, c_swap);
      r_swap = min(N - r_swap, r_swap);
    }
    return (c_swap + r_swap) / 2;
  }
};
