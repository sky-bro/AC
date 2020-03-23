#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 private:
  int di[8] = {1, 1, 1, 0, 0, -1, -1, -1};
  int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int m, n;

 public:
  vector<vector<char>> updateBoard(vector<vector<char>> &board,
                                   vector<int> &click) {
    m = board.size();
    n = board[0].size();
    stack<pair<int, int>> stk;
    int i = click[0], j = click[1];
    if (board[i][j] == 'M') {
      board[i][j] = 'X';
      return board;
    }
    vector<vector<bool>> vis(m, vector<bool>(n));
    stk.emplace(i, j);
    while (!stk.empty()) {
      i = stk.top().first;
      j = stk.top().second;
      vis[i][j] = true;
      stk.pop();
      int cnt_mine = 0;
      for (int k = 0; k < 8; ++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
        if (board[ni][nj] == 'M') ++cnt_mine;
      }
      if (cnt_mine) {
        board[i][j] = cnt_mine + '0';
        continue;
      }
      board[i][j] = 'B';
      for (int k = 0; k < 8; ++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj]) continue;
        stk.emplace(ni, nj);
      }
    }
    return board;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

template <typename T>
void printArr2D(const vector<vector<T>> &arr2D) {
  for (const auto &vt : arr2D) printArr(vt);
}

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'M', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'}};
  vector<int> click = {3, 0};
  printArr2D(s.updateBoard(board, click));
  return 0;
}
