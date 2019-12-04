// https://leetcode.com/problems/next-permutation/discuss/415598/C%2B%2B-simple-solution-0ms-beat-100-and-Python-simple-solution
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cur = 0;
        
        for (int i = nums.size()-1; i > 0; --i) {
            // 从后向前寻找，找到第一个顺序元素(从小到大的顺序)
            // 这时nums[i:]是按从大到小的顺序 -- 因为一直没有进入过if语句，若进入了则会break出去，不会再执行这个判断
            if (nums[i-1] < nums[i]) {
                // cur保存逆序的第一个元素
                cur = i;
                // 寻找最小的比nums[i-1]大的元素，这里从左往右或是从右往左寻找都是可以的，只要在最小满足的位置break出来
                int exchange = i;
                // for (int j = i; j < nums.size(); ++j)
                //     if (nums[j] > nums[i-1])
                //         exchange = j;
                //     else
                //         break;
                for (int j = nums.size()-1; ; --j) // 从右往左寻找，即从小到大寻找
                    if (nums[j] > nums[i-1]) {
                        exchange = j;
                        break;
                    }

                // 交换，使得序号增加最小
                swap(nums[exchange], nums[cur-1]);
                break;
            }
        }
        // 反转，变为从小到大
        reverse(nums.begin()+cur,nums.end());
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums({2,3,1});
    for (auto x: nums) {
        cout<<x<<" ";
    }
    cout<<endl;
    Solution s;
    s.nextPermutation(nums);
    for (auto x: nums) {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
