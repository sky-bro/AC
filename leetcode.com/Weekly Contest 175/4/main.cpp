#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// dfs: TLE, not sure if it is right

// class Solution {
// private:
//     vector<pair<int, int>> seats;
//     int total_seats;
//     int m, n;
//     int result = 0;
//     void dfs(int idx, int cur_cnt, vector<vector<bool>> &visited) {
//         // if (total_seats - idx + cur_cnt <= result) return;
//         if (idx == total_seats) {
//             if (result < cur_cnt) result = cur_cnt;
//             return;
//         }
//         // dfs(idx+1, cur_cnt, visited);
//         int i = seats[idx].first, j = seats[idx].second;
//         if (!(visited[i][j-1] || visited[i-1][j-1] || visited[i-1][j+1])) {
//             visited[i][j] = true;
//             dfs(idx+1, cur_cnt+1, visited);
//             visited[i][j] = false;
//         }
        
//         dfs(idx+1, cur_cnt, visited);
//     }
// public:
//     int maxStudents(vector<vector<char>>& seats) {
//         m = seats.size();
//         n = seats[0].size();
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (seats[i][j] == '.') {
//                     this->seats.emplace_back(i+1, j+1);
//                 }
//             }
//         }
//         total_seats = this->seats.size();
//         if (total_seats <= 1) return total_seats;
//         vector<vector<bool>> visited(m+1, vector<bool>(n+2));
//         dfs(0, 0, visited);
//         return result;
//     }
// };

// still TLE, need dp, see: https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem
// class Solution {
// private:
//     int m, n, max_sum = 0;
//     vector<uint8_t> seats;

//     inline uint8_t getRow(vector<vector<char>>& seats, int idx) {
//         uint8_t row = 0;
//         uint8_t mask = 1;
//         for (int i = 0; i < n; ++i) {
//             if (seats[idx][i] == '.') {
//                 row |= mask;
//             }
//             mask<<=1;
//         }
//         return row;
//     }

//     void dfs(int i, int j, int cur_sum, uint8_t mask) {
//         if (j == n) {
//             if (i == m-1) {
//                 if (cur_sum > max_sum) max_sum = cur_sum;
//             } else {
//                 uint8_t saved_row = seats[i+1];
//                 seats[i+1] &= ~((seats[i] << 1) | (seats[i] >> 1));
//                 dfs(i+1, 0, cur_sum, 1);
//                 seats[i+1] = saved_row;
//             }
//             return;
//         }
//         if ((seats[i] & mask) == 0) {
//             dfs(i, j+1, cur_sum, mask<<1);
//             return;
//         }
//         if ((seats[i] & (mask>>1)) == 0) {
//             dfs(i, j+1, cur_sum+1, mask<<1);
//         }
//         seats[i] ^= mask;
//         dfs(i, j+1, cur_sum, mask<<1);
//         seats[i] ^= mask;
//     }
// public:
//     int maxStudents(vector<vector<char>>& seats) {
//         m = seats.size(), n = seats[0].size();
//         for (int i = 0; i < m; ++i) {
//             this->seats.push_back(getRow(seats, i));
//         }
//         dfs(0, 0, 0, 1);
//         return max_sum;
//     }
// };

// 0ms, double 100%
class Solution {
private:
    int m, n;

    inline int popcnt(uint8_t num) {
        int cnt = 0;
        while (num) {
            if (num&1) ++cnt;
            num >>= 1;
        }
        return cnt;
    }

public:
    int maxStudents(vector<vector<char>>& seats) {
        m = seats.size(), n = seats[0].size();
        vector<uint8_t> seats_bits;
        vector<vector<int>> dp(m+1, vector<int>(1 << n));
        vector<uint8_t> possible_mask;

        for (int i = 0; i < m; ++i) {
            uint8_t row = 0;
            uint8_t mask = 1;
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    row |= mask;
                }
                mask <<= 1;
            }
            seats_bits.push_back(row);
        }

        for (int i = 0; i < (1 << n); ++i) {
            if (i & (i << 1)) continue;
            possible_mask.push_back(i);
        }

        for (int i = 1; i <= m; ++i) {
            for (uint8_t j: possible_mask) {
                if ((j & seats_bits[i-1]) == j) {
                    for (uint8_t k: possible_mask) {
                        if (j == (j & ~(k << 1 | k >> 1)))
                            // dp[i][j] = max(dp[i][j], dp[i-1][k] + /*popcnt(j)*/ __builtin_popcount(j));
                            dp[i][j] = max(dp[i][j], dp[i-1][k] + popcnt(j));
                    }
                }
            }
        }

        return *max_element(dp[m].begin(), dp[m].end());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> seats = {{'#','.','.','.','#'},{'.','#','.','#','.'},{'.','.','#','.','.'},{'.','#','.','#','.'},{'#','.','.','.','#'}}; // 10
    seats = {{'#','.','#','#','.','#'},{'.','#','#','#','#','.'},{'#','.','#','#','.','#'}}; // 4
    seats = {{'.','.','.','.','#','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','#','.'},{'.','.','.','.','.','.','.','.'},{'.','.','#','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','#','.','.','#','.'}}; // 31
    cout<<s.maxStudents(seats)<<endl;
    return 0;
}
