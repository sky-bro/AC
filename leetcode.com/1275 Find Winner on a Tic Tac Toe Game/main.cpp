#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool hasWin(int mat[3][3], vector<int>& move, int player) {
        int i;
        for (i = 0; i < 3; ++i) {
            if (mat[move[0]][i] != player) break;
        }
        if (i == 3) return true;

        for (i = 0; i < 3; ++i) {
            if (mat[i][move[1]] != player) break;
        }
        if (i == 3) return true;

        if ((move[0] == move[1] && mat[0][0] == player && mat[1][1] == player && mat[2][2] == player) ||
         (move[0] + move[1] == 2 && mat[0][2] == player && mat[1][1] == player && mat[2][0] == player)) {
            return true;
        }
        return false;
    }

public:
    string tictactoe(vector<vector<int>>& moves) {
        int mat[3][3] = {{0}};
        int player = 2, n = moves.size();
        for (auto &move: moves) {
            player = player==1?2:1;
            mat[move[0]][move[1]] = player;
        }
        
        if (hasWin(mat, moves[n-1], player)) {
            return player == 1?"A":"B";
        }
        return n==9?"Draw":"Pending";
    }
};
