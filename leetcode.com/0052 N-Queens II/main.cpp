#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _totalNQueens(int &result, vector<int> &path, int r, int n) {
        if (r == n) {
            ++result;
            return;
        }
        for (int c = 0; c < n; ++c) {
            int _r = 0;
            for (; _r < r; ++_r) {
                if (path[_r] == c || r - _r == abs(c - path[_r])) {
                    break;
                }
            }
            if (_r != r) continue;
            path.push_back(c);
            _totalNQueens(result, path, r+1, n);
            path.pop_back();
        }
    }
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> path;
        _totalNQueens(result, path, 0, n);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.totalNQueens(4)<<endl;
    return 0;
}