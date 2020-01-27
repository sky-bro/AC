#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<int> indegrees(numCourses, 0);
        vector<int> stk;
        for (auto& prerequisite: prerequisites) {
            indegrees[prerequisite[0]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) stk.push_back(i);
        }
        while (!stk.empty()) {
            int tmp = stk.back(); stk.pop_back();
            order.push_back(tmp); indegrees[tmp]--;
            for (auto& prerequisite: prerequisites) {
                if (prerequisite[1] == tmp)
                    indegrees[prerequisite[0]]--;
            }
            if (stk.empty()) // 减少遍历次数
                for (int i = 0; i < numCourses; ++i) {
                    if (indegrees[i] == 0) stk.push_back(i);
                }
        }
        if (numCourses == order.size()) return order;
        return {};
    }
};