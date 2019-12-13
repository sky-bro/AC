#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
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
        for (auto &interval: intervals) {
            if (interval[0] <= result[i][1]) {
                if (interval[1] > result[i][1]) {
                    result[i][1] = interval[1];
                }
            } else {
                result.push_back(interval);
                ++i;
            }
        }
        return result;
    }
};