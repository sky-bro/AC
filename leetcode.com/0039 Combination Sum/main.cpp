#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> _combinationSum(vector<int> &candidates, int target, int start_idx) {
        vector<vector<int>> result;
        int n = candidates.size();
        for (int i = start_idx; i < n && candidates[i] <= target; ++i) {
            vector<int> vi;
            if (candidates[i] == target) {
                vi.push_back(target);
                result.push_back(vi);
                continue;
            }
            auto prev_results = _combinationSum(candidates, target - candidates[i], i);
            for (auto prev_result: prev_results) {
                prev_result.insert(prev_result.begin(), candidates[i]);
                result.push_back(prev_result);
            }
        }
        return result;        
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return _combinationSum(candidates, target, 0);
    }
};