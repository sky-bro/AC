#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n, max_side_length;
    int _maximalSquare(vector<vector<char>>& matrix, vector<vector<int>>& side_lengths, int i, int j) {
        if (side_lengths[i][j] != -1) return side_lengths[i][j];
        if (matrix[i][j] == '0') return side_lengths[i][j] = 0;
        if (i == m-1 || j == n-1) return side_lengths[i][j] = 1;
        int sub_side_lengths1 = _maximalSquare(matrix, side_lengths, i, j+1); // right
        int sub_side_lengths2 = _maximalSquare(matrix, side_lengths, i+1, j); // down
        int sub_side_lengths3 = _maximalSquare(matrix, side_lengths, i+1, j+1); // right & down
        return 1 + min(sub_side_lengths1, min(sub_side_lengths2, sub_side_lengths3));
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(); if (m == 0) return 0;
        n = matrix[0].size(); if (n == 0) return 0;
        max_side_length = 0;
        vector<vector<int>> side_lengths(m, vector<int>(n, -1));
        for (int i = 0; i < m - max_side_length; ++i) {
            for (int j = 0; j < n - max_side_length; ++j) {
                if (matrix[i][j] == '0') continue;
                max_side_length = max(max_side_length, _maximalSquare(matrix, side_lengths, i, j));
            }
        }
        return max_side_length * max_side_length;
    }
};