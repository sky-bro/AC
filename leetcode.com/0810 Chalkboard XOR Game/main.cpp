#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// TLE

// class Solution {
//  private:
//   int n;
//   bool chk(vector<int>& nums, vector<bool>& vis, int cur) {
//     for (int i = 0; i < n; ++i) {
//       if (!vis[i] && (cur ^ nums[i])) {
//         vis[i] = true;
//         bool opponent_win = chk(nums, vis, cur ^ nums[i]);
//         vis[i] = false;
//         if (!opponent_win) return true;  // opponent loses, I win
//       }
//     }
//     return false;
//   }

//  public:
//   bool xorGame(vector<int>& nums) {
//     int cur = accumulate(nums.begin(), nums.end(), 0,
//                          [](int a, int b) { return a ^ b; });
//     if (cur == 0) return true;
//     n = nums.size();
//     vector<bool> vis(n);
//     return chk(nums, vis, cur);
//   }
// };

// math
// ref: [C++/Java/Python] 3-lines Easy Solution with Complaint and Explanation]
// https://leetcode.com/problems/chalkboard-xor-game/discuss/121696/C%2B%2BJavaPython-3-lines-Easy-Solution-with-Complaint-and-Explanation

class Solution {
 public:
  bool xorGame(vector<int>& nums) {
    return !(accumulate(nums.begin(), nums.end(), 0,
                        [](int a, int b) { return a ^ b; }) &&
             nums.size() & 1);
  }
};
