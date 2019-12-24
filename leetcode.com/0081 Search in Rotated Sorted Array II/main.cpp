#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
       for (auto x: nums) {
           if (x == target) return true;
       }
       return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 3, 6};
    int target = 1;
    Solution s;
    cout<<boolalpha<<s.search(nums, target)<<endl;
    return 0;
}
