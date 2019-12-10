#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), tmp;
        for (int r = 0; r < n/2; ++r) {
            for (int c = r; c < n-1-r; ++c) {
                int r1 = c, c1 = n-1-r;
                int r2 = c1, c2 = n-1-r1;
                int r3 = c2, c3 = n-1-r2;
                tmp = matrix[r][c];
                matrix[r][c] = matrix[r3][c3];
                matrix[r3][c3] = matrix[r2][c2];
                matrix[r2][c2] = matrix[r1][c1];
                matrix[r1][c1] = tmp;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Solution s;
    s.rotate(matrix);
    for (auto &vi: matrix) {
        for (auto &i: vi) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
