#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, len = 0, n = nums.size();
        if (n <= 1) return n;
        for (;i<n;++i){
            if (nums[len] != nums[i]) {
                nums[++len] = nums[i];
            }
        }
        ++len;
        nums.resize(len);
        return len;
    }

    // 2 line
    // int removeDuplicates(vector<int>& nums) {
    //     nums.erase(unique(nums.begin(), nums.end()), nums.end());
    //     return nums.size();
    // }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
