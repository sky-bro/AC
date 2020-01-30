#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n, max_side_length;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(); if (m == 0) return 0;
        n = matrix[0].size(); if (n == 0) return 0;
        max_side_length = 0;
        vector<vector<int>> side_lengths(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            if (matrix[m-1][i] == '1') side_lengths[m-1][i] = max_side_length = 1;
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][n-1] == '1') side_lengths[i][n-1] = max_side_length = 1;
        }

        for (int i = m-2; i >= 0; --i) {
            for (int j = n-2; j >= 0; --j) {
                if (matrix[i][j] == '0') side_lengths[i][j] = 0;
                else {
                    side_lengths[i][j] = 1 + min(side_lengths[i][j+1], min(side_lengths[i+1][j], side_lengths[i+1][j+1]));
                }
                max_side_length = max(max_side_length, side_lengths[i][j]);
            }
        }
        return max_side_length * max_side_length;
    }
};