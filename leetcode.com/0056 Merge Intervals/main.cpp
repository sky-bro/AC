#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[0] < b[0]) return true;
    if (a[0] == b[0]) return a[1] > b[1];
    return false;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        if (n <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        int i = 0, j = 1;
        for (int j = 1; j < n; ++j) {
            if (intervals[j][0] <= result[i][1]) {
                if (intervals[j][1] > result[i][1]) {
                    result[i][1] = intervals[j][1];
                }
            } else {
                result.push_back(intervals[j]);
                ++i;
            }
        }
        return result;
    }
};