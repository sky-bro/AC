#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // brute force
        int cnt=0;
        bool row[9][9] = { false }, col[9][9] = { false }, box[9][9] = { false };

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                cnt++;
                int val_ind = board[r][c] - '1';
                int box_ind = r / 3 * 3 + c / 3;
                row[r][val_ind] = col[c][val_ind] = box[box_ind][val_ind] = true;
            }
        }
        
        while (true) {
            for (int r = 0; r < 9; ++r) {
                for (int c = 0; c < 9; ++c) {
                    if (board[r][c] != '.') continue;
                    int solved = -1, i = 0;
                    for (; i < 9; ++i) {
                        if (col[c][i] || row[r][i] || box[r/3*3+c/3][i]) continue;
                        if (solved != -1) {
                            break;
                        } else {
                            solved = i;
                        }
                    }
                    if (solved != -1 && i == 9) {
                        board[r][c] = solved + '1';
                        col[c][solved] = row[r][solved] = box[r/3*3+c/3][solved] = true;
                        if (++cnt == 81) return;
                    }
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    // time limit exceeded
    vector<vector<char>> board2 = {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
    Solution s;
    s.solveSudoku(board);
    for (auto &row: board) {
        for (auto &v: row) {
            cout<<v<<" ";
        }
        cout<<endl;
    }

    s.solveSudoku(board2);
    for (auto &row: board2) {
        for (auto &v: row) {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}
