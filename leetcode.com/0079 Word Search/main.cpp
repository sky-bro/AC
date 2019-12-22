#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n, word_len;
    vector<vector<bool>> visited;
    bool _exist(int idx, string &word, int i, int j, vector<vector<char>> &board) {
        if (board[i][j] != word[idx]) return false;
        if (idx == word_len - 1) return true;
        visited[i][j] = true;
        bool result = false;
        if (i + 1 < m && !visited[i+1][j] && _exist(idx+1, word, i+1, j, board)
        || i - 1 >= 0 && !visited[i-1][j] && _exist(idx+1, word, i-1, j, board)
        || j + 1 < n && !visited[i][j+1] && _exist(idx+1, word, i, j+1, board)
        || j - 1 >= 0 && !visited[i][j-1] && _exist(idx+1, word, i, j-1, board)) {
            result = true;
        }
        visited[i][j] = false;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        m = board.size();
        n = board[0].size();
        word_len = word.length();
        visited = vector<vector<bool>>(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (_exist(0, word, i, j, board)) return true;
            }
        }
        return false;
    }
};