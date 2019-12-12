#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        int r = 0, c = 0, direction = 0;
        result.push_back(matrix[0][0]);
        int max_right = n-1, max_down = m-1, max_left = 0, max_up = 0;
        for (int cnt = 1; cnt < m*n;) {
            switch (direction)
            {
            case 0:
                // 右
                cnt += max_right - c;
                ++max_up;
                direction = 1;
                for (c = c + 1; c <= max_right; ++c) {
                    result.push_back(matrix[r][c]);
                }
                --c;
                break;
            case 1:
                // 下
                cnt += max_down - r;
                --max_right;
                direction = 2;
                for (r = r + 1; r <= max_down; ++r) {
                    result.push_back(matrix[r][c]);
                }
                --r;
                break;
            case 2:
                // 左
                cnt += c - max_left;
                --max_down;
                direction = 3;
                for (c = c - 1; c >= max_left; --c) {
                    result.push_back(matrix[r][c]);
                }
                ++c;
                break;
            case 3:
                // 上
                cnt += r - max_up;
                ++max_left;
                direction = 0;
                for (r = r - 1; r >= max_up; --r) {
                    result.push_back(matrix[r][c]);
                }
                ++r;
                break;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    Solution s;
    vector<int> vi = s.spiralOrder(matrix);
    for (int i: vi){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
