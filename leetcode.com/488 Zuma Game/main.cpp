#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

// ref: Standard test program is wrong? (test case "RRWWRRBBRR", "WB")
// https://leetcode.com/problems/zuma-game/discuss/97007/Standard-test-program-is-wrong
const char *COLOR = "RYBGW";
class Solution {
 private:
  unordered_map<string, unordered_map<string, int>> dp;
  void merge(string &board, int &l, int &r) {
    int i = l - 1, j = r, n = board.size();
    if (i < 0 || j >= n || board[i] != board[j]) return;
    while (i >= 0 && board[i] == board[l - 1]) --i;
    int len = l - 1 - i;
    while (j < n && board[j] == board[r]) ++j;
    len += j - r;
    if (len >= 3) {
      l = i + 1;
      r = j;
      merge(board, l, r);
    }
  }
  // RYBGW
  int dfs(string board, string hand) {
    if (board.empty())
      return 0;
    else if (hand.empty())
      return -1;

    if (dp[board].count(hand)) return dp[board][hand];

    int res = -1;
    for (int j = 0; j < hand.size(); ++j) {
      string new_hand = hand.substr(0, j) + hand.substr(j + 1);
      for (int i = 0; i <= board.size(); ++i) {
        if (i < board.size() && hand[j] == board[i]) {
          int len = 1;
          while (i + len < board.size() && hand[j] == board[i + len]) ++len;
          if (len >= 2) {
            int l = i, r = i + len;
            merge(board, l, r);
            string new_board = board.substr(0, l) + board.substr(r);
            int cur_res = dfs(new_board, new_hand);
            if (cur_res != -1 && ((res == -1) || cur_res + 1 < res))
              res = cur_res + 1;
          } else {
            string new_board = board.substr(0, i);
            new_board.push_back(hand[j]);
            new_board += board.substr(i);
            int cur_res = dfs(new_board, new_hand);
            if (cur_res != -1 && ((res == -1) || cur_res + 1 < res))
              res = cur_res + 1;
          }
          i += len - 1;
        } else {
          if (i > 0 && board[i - 1] == hand[j]) continue;
          string new_board = board.substr(0, i);
          new_board.push_back(hand[j]);
          new_board += board.substr(i);
          int cur_res = dfs(new_board, new_hand);
          if (cur_res != -1 && ((res == -1) || cur_res + 1 < res))
            res = cur_res + 1;
        }
      }
    }
    return dp[board][hand] = res;
  }

 public:
  int findMinStep(string board, string hand) {
    dp.clear();
    return dfs(board, hand);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string board = "WRRBBW";
  string hand = "RB";
  /*
  BBYGBRWYGBGRWYBW YB
  */
  while (cin >> board >> hand) {
    cout << s.findMinStep(board, hand) << endl;
  }
  return 0;
}
