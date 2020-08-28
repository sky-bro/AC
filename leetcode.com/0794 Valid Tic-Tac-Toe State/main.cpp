#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validTicTacToe(vector<string>& board) {
    int p1_cnt = 0, p2_cnt = 0;
    int winner = ' ';
    for (int i = 0; i < 9; ++i) {
      switch (board[i / 3][i % 3]) {
        case 'X':
          ++p1_cnt;
          break;
        case 'O':
          ++p2_cnt;
          break;
      }
    }
    if (!(p1_cnt == p2_cnt || p1_cnt - 1 == p2_cnt)) return false;
    // check rows
    for (int i = 0; i < 3; ++i) {
      if (board[i][0] != ' ' && board[i][0] == board[i][1] &&
          board[i][1] == board[i][2]) {
        if (winner != ' ') return false;
        winner = board[i][0];
      }
    }
    // check columns
    for (int i = 0; i < 3; ++i) {
      if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
          board[1][i] == board[2][i]) {
        if (winner == ' ') {
          winner = board[0][i];
          continue;
        }
        if (winner != 'X') return false;  // p1 takes 5 moves, p2 takes 4
        return p1_cnt == 5;
      }
    }
    // check diagonals
    if (board[1][1] != ' ') {
      if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (winner == ' ')
          winner = board[1][1];
        else if (winner != 'X')
          return false;  // p1 takes 5 moves, p2 takes 4
        else
          return p1_cnt == 5;
      }
      if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (winner == ' ')
          winner = board[1][1];
        else if (winner != 'X')
          return false;  // p1 takes 5 moves, p2 takes 4
        else
          return p1_cnt == 5;
      }
    }
    if (winner == ' ')
      return true;
    else if (winner == 'X')
      return p1_cnt > p2_cnt;
    else
      return p1_cnt == p2_cnt;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> board = {"XXO", "XOX", "OXO"};
  cout << s.validTicTacToe(board) << endl;
  return 0;
}
