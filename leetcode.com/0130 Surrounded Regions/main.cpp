#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int m, n;
    inline bool valid_ij(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(); if (m == 0) return;
        n = board[0].size(); if (n == 0) return;
        vector<int> diff_is = {1, -1, 0, 0};
        vector<int> diff_js = {0, 0, 1, -1};
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' || visited[i][j]) continue;

                // dfs
                bool stay_O = false;
                stack<pair<int, int>> stk;
                vector<pair<int, int>> Os;
                stk.push(make_pair(i, j));
                visited[i][j] = true;
                while (!stk.empty()) {
                    pair<int, int> p = stk.top(); stk.pop();
                    Os.push_back(p);
                    if (stay_O || p.first+1 == m || p.second+1 == n || p.first == 0 || p.second == 0) {
                        stay_O = true;
                    }
                    for (int i = 0; i < 4; ++i) {
                        if (valid_ij(p.first+diff_is[i], p.second+diff_js[i]) && board[p.first+diff_is[i]][p.second+diff_js[i]] == 'O' && !visited[p.first+diff_is[i]][p.second+diff_js[i]]) {
                            visited[p.first+diff_is[i]][p.second+diff_js[i]] = true;
                            stk.push(make_pair(p.first+diff_is[i], p.second+diff_js[i]));
                        }
                    }

                }
                if (stay_O) continue;
                for (auto &p: Os) {
                    board[p.first][p.second] = 'X';
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    vector<vector<char>> board2 = {
        {'X','O','O','X','X','X','O','X','O','O'},
        {'X','O','X','X','X','X','X','X','X','X'},
        {'X','X','X','X','O','X','X','X','X','X'},
        {'X','O','X','X','X','O','X','X','X','O'},
        {'O','X','X','X','O','X','O','X','O','X'},
        {'X','X','O','X','X','O','O','X','X','X'},
        {'O','X','X','O','O','X','O','X','X','O'},
        {'O','X','X','X','X','X','O','X','X','X'},
        {'X','O','O','X','X','O','X','X','O','O'},
        {'X','X','X','O','O','X','O','X','X','O'},
    };
    Solution s;
    s.solve(board2);
    return 0;
}
/*
[["X","O","O","X","X","X","O","X","O","O"]
,["X","O","X","X","X","X","X","X","X","X"]
,["X","X","X","X","O","X","X","X","X","X"]
,["X","O","X","X","X","O","X","X","X","O"]
,["O","X","X","X","O","X","O","X","O","X"]
,["X","X","O","X","X","O","O","X","X","X"]
,["O","X","X","O","O","X","O","X","X","O"]
,["O","X","X","X","X","X","O","X","X","X"]
,["X","O","O","X","X","O","X","X","O","O"]
,["X","X","X","O","O","X","O","X","X","O"]]

[["X","O","O","X","X","X","O","X","O","O"]
,["X","X","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","X","O"]
,["O","X","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","X","X"]
,["O","X","X","X","X","X","X","X","X","O"]
,["O","X","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","O","O"]
,["X","X","X","O","O","X","O","X","X","O"]]

[["X","O","O","X","X","X","O","X","O","O"]
,["X","O","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","X","O"]
,["O","X","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","X","X"]
,["O","X","X","X","X","X","X","X","X","O"]
,["O","X","X","X","X","X","X","X","X","X"]
,["X","X","X","X","X","X","X","X","O","O"]
,["X","X","X","O","O","X","O","X","X","O"]]

*/
