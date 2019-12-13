#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return vector<vector<int>>(1, newInterval);
        vector<vector<int>> result;
        int i = 0, j = 0;
        for (;j < n;) {
            if (newInterval[0] <= intervals[j][0]) {
                result.push_back(newInterval);
                ++i;
                break;
            }
            result.push_back(intervals[j++]);
            ++i;
            if (newInterval[0] <= result[i-1][1]) {
                if (newInterval[1] > result[i-1][1]) {
                    result[i-1][1] = newInterval[1];
                }
                break;
            }
        }

        if (j == n) {
            if (newInterval[0] > result[i-1][1]) {
                result.push_back(newInterval);
            }
            return result;
        }

        for (; j < n; ++j) {
            if (result[i-1][1] >= intervals[j][0]) {
                if (intervals[j][1] > result[i-1][1]) {
                    result[i-1][1] = intervals[j][1];
                }
            } else {
                break;
            }
        }
        result.insert(result.end(), intervals.begin() + j, intervals.end());
        return result;
    }
};