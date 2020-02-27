#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// ref: use bitset
// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90590/Simple-C%2B%2B-4-line-solution-using-a-bitset
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    bitset<10001> bits(1);
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (int num : nums) bits |= bits << num;
    return !(sum & 1) && bits[sum >> 1];
  }
};