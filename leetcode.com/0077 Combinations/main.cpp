#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void _combine(int start, int end, int k, vector<int> &path, vector<vector<int>> &result) {
        if (k == 0) {
            result.push_back(path);
            return;
        }

        path.push_back(start);
        _combine(start+1, end, k-1, path, result);
        path.pop_back();

        if (k < end - start + 1) {
            _combine(start+1, end, k, path, result);
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        _combine(1, n, k, path, result);
        return result;
    }
};