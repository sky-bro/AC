#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r, c, m = matrix.size(), n = matrix[0].size();
        for (r = 0; r < m; ++r) {
            for (c = 0; c < n; ++c) {
                if (!matrix[r][c]) break;
            }
            if (c != n) break;
        }

        if (r == m) return;

        for (int i = r; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!matrix[i][j]) {
                    matrix[r][j] = 0;
                    matrix[i][c] = 0;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i == c) continue;
            if (!matrix[r][i])
                for (int j = 0; j < m; ++j)
                    matrix[j][i] = 0;
            else
                matrix[r][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            if (i == r) continue;
            if (!matrix[i][c])
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
            else
                matrix[i][c] = 0;
        }
    }
};