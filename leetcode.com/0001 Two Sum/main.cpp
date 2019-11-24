#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            auto iter = m.find(target - nums[i]);
            if (iter != m.end()) {
                v.push_back(i);
                v.push_back(iter->second);
                break;
            }
            m.insert({nums[i], i});
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec{1,2,3,4};
    const vector<int> &v2 = s.twoSum(vec, 7);
    cout<<v2[0]<<endl;
    cout<<v2[1]<<endl;
    return 0;
}
