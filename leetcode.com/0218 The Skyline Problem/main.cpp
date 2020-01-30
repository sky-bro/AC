#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp
{
    // 按照房屋高度排序
    bool operator()(vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    }
};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        if (buildings.empty()) return result;

        // part 1
        // 按照左边坐标从小到大排序
        sort(buildings.begin(), buildings.end(), [](vector<int>& a, vector<int>& b){ return a[0] != b[0] ? a[0] < b[0] : a[2] > b[2]; });
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for (auto &building: buildings) {
            int prev_height = 0;
            while (!pq.empty()) {
                auto& prev_building = pq.top();
                
                if (prev_building[1] < building[0]) {
                    // 结束早于当前开始，忽略
                    pq.pop();
                } else {
                    if (prev_building[2] >= building[2]) {
                        // 还没结束的建筑不矮于当前建筑
                        prev_height = INT32_MAX;
                    } else {
                        // 还没结束的建筑矮于当前建筑
                        prev_height = 0;
                    }
                    break;
                }
            }
            if (prev_height == 0) result.push_back({building[0], building[2]});
            pq.push(building);
        }

        // part 2
        // 按照右边坐标从大到小排序
        sort(buildings.begin(), buildings.end(), [](vector<int>& a, vector<int>& b){ return a[1] != b[1] ? a[1] > b[1] : a[2] > b[2]; });
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq2;
        pq2.push({0, buildings[0][1], 0}); // 地平线，高度为0，横跨所有建筑
        for (auto &building: buildings) {
            int prev_height = INT32_MAX;
            while (!pq2.empty()) {
                auto& prev_building = pq2.top();
                
                if (prev_building[0] > building[1]) {
                    // 开始晚于当前结束，忽略
                    pq2.pop();
                } else {
                    if (prev_building[2] < building[2]) {
                        // 还没结束的建筑矮于当前建筑
                        prev_height = prev_building[2];
                    }
                    break;
                }
            }
            if (prev_height != INT32_MAX) result.push_back({building[1], prev_height});
            pq2.push(building);
        }

        // part 3
        // 把前两部分找到的关键点合并起来排序
        sort(result.begin(), result.end(), [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; });
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    s.getSkyline(buildings);
    return 0;
}
