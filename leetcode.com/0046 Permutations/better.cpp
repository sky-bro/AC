#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        vector<int> visited(nums.size(), 0);
        dfs(nums, 0, visited, path, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int step, vector<int>& visited, vector<int>& path, vector<vector<int>>& res){
        if(step==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==1) continue;
            path.push_back(nums[i]);
            visited[i]=1;
            dfs(nums,step+1,visited,path,res);
            path.pop_back();
            visited[i]=0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,2,3};
    auto result = s.permute(nums);
    for (auto &vi: result){
        for (auto &i: vi) {
            cout<< i << " ";
        }
        cout<<endl;
    }
    return 0;
}
