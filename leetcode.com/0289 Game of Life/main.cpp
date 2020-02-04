#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int height = board.size(),width = height?board[0].size():0;
        for(int i=0;i<height;i++){
            for(int j = 0;j< width;j++){
                int cnt = 0;
                for(int ii = max(0,i-1);ii<min(i+2,height);ii++){
                    for(int jj = max(0,j-1);jj<min(j+2,width);jj++){
                        cnt+=board[ii][jj] & 1;
                    }
                }
                if(cnt==3||cnt-board[i][j]==3)
                    board[i][j] |=2;
            }
        }
        for(int i = 0;i<height;i++)
            for(int j =0;j<width;j++)
                board[i][j] >>= 1;
    }
};