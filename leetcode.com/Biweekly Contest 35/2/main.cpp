#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long S = accumulate(nums.begin(), nums.end(), 0LL);
        if (S < p) return -1;
        if (S%p == 0) return 0;
        int r = S%p;
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        mp[0].push_back(-1);
        long long cur = 0;
        int res = -1;
        for (int i = 0; i < n; ++i) {
          cur = (cur + nums[i]) % p;
          mp[cur].push_back(i);
          int other = (cur - r + p) % p;
          auto it = mp.find(other);
          if (it == mp.end()) continue;
          int dis = i - it->second.back();
          if (res == -1 || dis < res) res = dis;
        }
        if (res == n) return -1;
        return res;
    }
};
