#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, array<int, 3>> m;
        for (int i = nums.size()-1; i >= 0; --i) {
          auto it = m.find(nums[i]);
          if (it == m.end()) {
            m[nums[i]] = {1, i, i};
          } else {
            it->second[0]++;
            it->second[1] = i;
          }
        }
        int max_freq = 1, max_len = 1;
        for (auto &arr: m) {
          if (arr.second[0] == max_freq) {
            max_len = min(max_len, arr.second[2]-arr.second[1] + 1);
          } else if (arr.second[0] > max_freq) {
            max_freq = arr.second[0];
            max_len = arr.second[2] - arr.second[1] + 1;
          }
        }
        return max_len;
    }
};