#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    void dfs(vector<int> &candidates, vector<vector<int>> &res, int start, int target, int currSum, vector<int> &path) {
        if (currSum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (currSum + candidates[i] <= target) {
                path.push_back(candidates[i]);
                dfs(candidates, res, i, target, currSum + candidates[i], path);
                path.pop_back();
            }
        }
        return;
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) {
            return res;
        }
        vector<int> path;
        dfs(candidates, res, 0, target, 0, path);
        return res;
    }
};

/*

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort( candidates.begin(), candidates.end());
        if( candidates.empty() || candidates[0] > target)
            return res;
        
        this->target = target;
        vector<int> tmp;
        findCombinationSum( candidates, 0, 0, tmp);
        
        return res;
    }
private:
    int target;
    vector< vector<int> > res;
    
    void findCombinationSum( const vector<int>& candidates, int pt, int sum, vector<int>& tmp) {
        
        if( sum == target) {
            res.push_back( tmp);
            return;
        }
        
        for( int i=pt; i<candidates.size(); ++i) {
            if( sum + candidates[i]> target)
                break;
            else { // sum + candidates[i] <= target
                tmp.push_back( candidates[i]);
                findCombinationSum( candidates, i, sum + candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
};

*/