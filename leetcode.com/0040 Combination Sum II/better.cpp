#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        
        sort(candidates.begin(), candidates.end());
        
        if(candidates.empty() || target < candidates[0]) return ans;
        
        vector<int> temp;
        
        tree(ans, candidates, temp, 0, 0, target);
    
        return ans;
    }
    
    
    void tree(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& temp, int last_p, int sum, int target)
    {
        
        if(sum == target)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = last_p; i < candidates.size(); i++)
        {
            if(sum + candidates[i] > target) break;
                 
            if(i != last_p && candidates[i] == candidates[i - 1]) continue;
        
            temp.push_back(candidates[i]);
            tree(ans,candidates, temp, i + 1 , sum + candidates[i], target);
            temp.pop_back();    
        }
        
    }
    
};

/*

class Solution {
private:
    // This will filter for duplicates (permutations) by observing the combinations already
	// in the answer vector (resVec)
    bool isPermute(vector<int>& singleIter, const vector<vector<int>>& resVec) {
        if (resVec.size() == 0) return false; // If our resVec is empty, it's our first permutation
        // so we want to push it back immediately (no check needed);
        for (int i{}; i < resVec.size(); i++) {
            if (is_permutation(resVec[i].begin(), resVec[i].end(), singleIter.begin())) return true;
        }
        return false;
    }
    
    void combinationHelper(vector<vector<int>>& resVec, vector<int>& singleIter, const vector<int>& candidates, int sum, int pos, const int& target) {
        if (sum == target) {
            if (isPermute(singleIter, resVec)) return; // If a permutation of this 
            // combination exists. we don't want it in our result.
            resVec.push_back(singleIter);
        } 
        
        for (int i{pos}; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; // No point in considering an item that's greater
            // than the total. Increase performance here.
            if (sum + candidates[i] > target) continue; // No point in adding a value that will lead
            // to a combination greater than our target. Let's observe the next number in candidates
            singleIter.push_back(candidates[i]);
            combinationHelper(resVec, singleIter, candidates, sum + candidates[i], i + 1, target);
            singleIter.pop_back();
        }
        
        return;
    }
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> resVec; // This will store our answer
        resVec.reserve(10);
        
        vector<int> singleIter; // This iwll store a single iteration of our combination
        singleIter.reserve(10);
        int total{}; // We will track the sum of our singleIteration
        
        combinationHelper(resVec, singleIter, candidates, total, 0, target); // Manipulate the resVec
        return resVec; // Return the resVec;
    }
};

*/