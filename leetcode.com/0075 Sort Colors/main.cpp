#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, i = 0;
        while (l < r) {
            if (nums[l] == 2) {
                if (nums[r] == 0)
                    swap(nums[l++], nums[r--]);
                else if (nums[r] == 1)
                    swap(nums[l], nums[r--]);
            } else if (nums[l] == 1 && nums[r] == 0) {
                swap(nums[l++], nums[r]);
            }

            if (nums[l] == 0) ++l;
            if (nums[r] == 2) --r;

            if (nums[l] == 1 && nums[r] == 1) {
                if (i < l + 1) i = l + 1;
                for (; i <= r; ++i) {
                    if (nums[i] == 0) swap(nums[l++], nums[i]);
                    else if (nums[i] == 2) {
                        swap(nums[r--], nums[i++]);
                        break;
                    }
                }
                if (i > r) break;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vi = {1,1,0,0,1,1};
    Solution s;
    s.sortColors(vi);
    return 0;
}
