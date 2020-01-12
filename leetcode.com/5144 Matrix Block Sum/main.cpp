#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n));

        // first element
        for (int i = 0; i <= K && i < m; ++i) {
            for (int j = 0; j <= K && j < n; ++j) {
                result[0][0] += mat[i][j];
            }
        }

        // first row of elements
        for (int i = 1; i < n; ++i) {
            result[0][i] = result[0][i-1];
            if (i - K > 0) {
                for (int j = 0; j <= K && j < m; ++j) {
                    result[0][i] -= mat[j][i-K-1];
                }
            }
            if (i + K < n) {
                for (int j = 0; j <= K && j < m; ++j) {
                    result[0][i] += mat[j][i+K];
                }
            }
        }

        // remaining rows
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = result[i-1][j];
                if (i - K > 0) {
                    for (int k = j - K >= 0 ? j - K : 0; k <= j + K && k < n; ++k) {
                        result[i][j] -= mat[i-K-1][k];
                    }
                }
                if (i + K < m) {
                    for (int k = j - K >= 0 ? j - K : 0; k <= j + K && k < n; ++k) {
                        result[i][j] += mat[i+K][k];
                    }
                }
            }
        }

        return result;
    }
};