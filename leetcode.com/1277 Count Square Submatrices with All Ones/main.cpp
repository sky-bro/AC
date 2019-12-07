#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), result = 0, i, max_r, max_c;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                for (int len = 1; len <= m - r && len <= n - c; ++len) {
                    max_r = r + len - 1;
                    max_c = c + len - 1;
                    for (i = r; i <= max_r && matrix[i][max_c]; ++i);
                    if (i <= max_r) break;
                    for (i = c; i <= max_c && matrix[max_r][i]; ++i);
                    if (i <= max_c) break;
                    ++result;
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> matrix = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };
    cout<<s.countSquares(matrix)<<endl;
    return 0;
}
