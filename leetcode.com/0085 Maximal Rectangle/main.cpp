#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int max_area = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    _maximalRectangle(matrix, i, j, max_area);
                }
            }
        }
        return max_area;
    }

    // ir: initial row, ic: initial column
    // cr: current row, rb: column boundary
    // cc: current column, cb: column boundary
    void _maximalRectangle(vector<vector<char>> &matrix, int ir, int ic, int &max_area) {
        int cb = 0;
        for (int cr = ir; cr >= 0; --cr) {
            int cc = ic;
            for (; cc >= cb; --cc) {
                if (matrix[cr][cc] == '0') {
                    break;
                }
            }
            if ((ic - cc) * (ir - cr + 1) > max_area) {
                max_area = (ic - cc) * (ir - cr + 1);
            }
            cb = cc + 1;
        }
    }

};
