#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return vector<vector<int>>(1, newInterval);
        vector<vector<int>> result;
        // i保存result中最后一个元素后面的索引
        // j保存下一个访问的intervals的索引
        int i = 0, j = 0;
        // 到result中刚看到
        for (;j < n;) {
            // newInterval是否能直接插入
            if (newInterval[0] <= intervals[j][0]) {
                result.push_back(newInterval);
                ++i;
                break;
            }
            result.push_back(intervals[j++]);
            ++i;
            // 刚放进去的intervals是否和newInterval有重合，有重合则把newInterval也插入（合并）
            if (newInterval[0] <= result[i-1][1]) {
                if (newInterval[1] > result[i-1][1]) {
                    result[i-1][1] = newInterval[1];
                }
                break;
            }
        }

        // 如果所有intervals都已插入 / intervals中所有元素都放入了result
        // 只需要检查是否需要再放入newInterval
        if (j == n) {
            // newInterval可能还没插入，直接插入到末尾
            if (newInterval[0] > result[i-1][1]) {
                result.push_back(newInterval);
            }
            // newInterval已插入，intervals已插入，返回
            return result;
        }

        // 还有intervals没有插入，这时result中最后一个元素是newIntervals（或者是它合并了前面的元素形成的）
        // 下面就将能与newInterval继续合并的元素合并进来
        for (; j < n; ++j) {
            if (result[i-1][1] >= intervals[j][0]) {
                if (intervals[j][1] > result[i-1][1]) {
                    result[i-1][1] = intervals[j][1];
                }
            } else {
                break;
            }
        }
        // intervals剩下的所有元素不改动，直接放到result最后
        result.insert(result.end(), intervals.begin() + j, intervals.end());
        return result;
    }
};