#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    int m, n;
    inline int getLiveNeighborCnt(int i, int j, vector<vector<int>> &board) {
        int cnt = - board[i][j];
        int up_bound = i - 1 >= 0 ? i - 1 : i;
        int down_bound = i + 1 < m ? i + 1 : i;
        int left_bound = j - 1 >= 0 ? j - 1 : j;
        int right_bound = j + 1 < n ? j + 1 : j;

        for (int r = up_bound; r <= down_bound; ++r) {
            for (int c = left_bound; c <= right_bound; ++c) {
                cnt += board[r][c];
            }
        }

        return cnt;

    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(); if (m == 0) return;
        n = board[0].size(); if (n == 0) return;
        vector<pair<int, int>> live;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live_neighbor_cnt = getLiveNeighborCnt(i, j, board);
                if (live_neighbor_cnt == 3 || live_neighbor_cnt == 2 && board[i][j]) {
                    live.push_back(pair(i, j));
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = 0;
            }
        }
        for (auto &p: live) {
            board[p.first][p.second] = 1;
        }

    }
};