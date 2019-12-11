#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _solveNQueens(vector<vector<string>> &result, vector<int> &path, char *dots, int r, int n) {
        if (r == n) {
            vector<string> _path;
            for (int i = 0; i < n; ++i) {
                dots[path[i]] = 'Q';
                _path.push_back(dots);
                dots[path[i]] = '.';
            }
            result.push_back(_path);
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
            _solveNQueens(result, path, dots, r+1, n);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        char *_dots = new char[n+1];
        for (int i = 0; i < n; ++i) _dots[i] = '.';
        _dots[n] = 0;
        vector<int> path;
        _solveNQueens(result, path, _dots, 0, n);
        delete [] _dots;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto vvs = s.solveNQueens(4);
    for (auto &vs: vvs) {
        for (auto &s: vs) {
            cout<<s<<endl;
        }
        cout<<endl;
    }
    return 0;
}
