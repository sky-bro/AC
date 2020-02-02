#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.first != b.first ? a.first < b.first : a.second < b.second;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        if (mat.empty()) return result;

        vector<pair<int, int>> arr;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int j = 0;
            for (; j < n && mat[i][j]; ++j);
            arr.push_back(pair(j, i));
        }
        sort(arr.begin(), arr.end(), cmp);
        for (int i = 0; i < k; ++i) {
            result.push_back(arr[i].second);
        }
        return result;
    }
};