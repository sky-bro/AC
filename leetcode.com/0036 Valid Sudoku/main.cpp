#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = { false }, col[9][9] = { false }, box[9][9] = { false };
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') continue;
                int val_ind = board[r][c] - '1';
                int box_ind = r / 3 * 3 + c / 3;
                if (row[r][val_ind] || col[c][val_ind] || box[box_ind][val_ind])
                    return false;
                row[r][val_ind] = col[c][val_ind] = box[box_ind][val_ind] = true;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    cout<<s.isValidSudoku(board)<<endl; // 0
    board[0][0]='5';
    cout<<s.isValidSudoku(board)<<endl; // 1
    return 0;
}
