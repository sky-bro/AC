#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][9] = { false }, col[9][9] = { false }, box[9][9] = { false };
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                int num = board[r][c] - '1';
                row[r][num] = col[c][num] = box[r/3*3+c/3][num] = true;
            }
        }
        solveSudoku(board, 0, row, col, box);
    }
private:
    bool solveSudoku(vector<vector<char>>& board, int pos, bool row[9][9], bool col[9][9], bool box[9][9]) {
        // goal is: when I reach the end, stop
        if(pos == 81) {
            return true;
        }
        int r = pos/9, c = pos%9;
        // choice 1: for 1~9, do nothing, check the next one
        if(board[r][c] != '.') {
            return solveSudoku(board, pos+1, row, col, box);
        }
        // choice 2: for '.', try all possible candidates
        for(int i = 0; i < 9; ++i) {
            // constrain: same row/col/block can't have duplicate elements
            // before put any candidate, check whether it is a valid solution
            if (row[r][i] || col[c][i] || box[r/3*3+c/3][i]) {
                continue;
            }
            board[r][c] = '1' + i;
            row[r][i] = col[c][i] = box[r/3*3+c/3][i] = true;
            if (solveSudoku(board, pos+1, row, col, box)) {
                return true;
            } else {
                row[r][i] = col[c][i] = box[r/3*3+c/3][i] = false;
            }
        }
        board[r][c] = '.';
        return false;
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
