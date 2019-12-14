#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        if (n == 0) return result;
        result[0][0] = 1;
        int max_right = n-1, max_down = n-1, max_left = 0, max_up = 0;
        int r = 0, c = 0;
        for (int i = 2; i <= n*n; ) {
            for (c+=1; c <= max_right; ++c) {
                result[r][c] = i++;
            }
            ++max_up;
            --c;
            for (r+=1; r <= max_down; ++r) {
                result[r][c] = i++;
            }
            --max_right;
            --r;

            for (c-=1; c >= max_left; --c) {
                result[r][c] = i++;
            }
            --max_down;
            ++c;

            for (r-=1; r >= max_up; --r) {
                result[r][c] = i++;
            }
            ++max_left;
            ++r;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while (cin>>n) {
        auto vvi = s.generateMatrix(n);
        for (auto &vi: vvi) {
            for (auto i: vi) {
                cout<<i<<"\t";
            }
            cout<<endl;
        }
    }
    return 0;
}
