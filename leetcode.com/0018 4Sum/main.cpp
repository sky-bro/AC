#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // [-3,-2,-1,0,0,1,2,3]
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l, r, sum;
        vector<vector<int>> vvi;
        for (int i = 0; i < n-3;) {
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            for (int j = i + 1; j < n-2;) {
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                l = j + 1; r = n - 1;
                while (l < r) {
                    sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) {
                        ++l;
                    } else if (sum > target) {
                        --r;
                    } else {
                        vvi.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l; --r;
                        for (;l<r&&nums[l] == nums[l-1]; ++l);
                        for (;l<r&&nums[r] == nums[r+1]; --r);
                    }
                }
                ++j;
                for (;j<n-2 && nums[j] == nums[j-1]; ++j);
            }
            ++i;
            for (;i<n-3 && nums[i] == nums[i-1]; ++i);
        }
        return vvi;
    }
};

struct Node {
    int data;
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v({-3,-2,-1,0,0,1,2,3});
    auto vvi = s.fourSum(v, 0);
    cout<<"Count: "<<vvi.size()<<endl;
    for (auto vi: vvi) {
        for (auto i: vi) {
            cout<<i<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
