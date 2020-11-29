#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

// ref:
// https://leetcode.com/problems/minimize-deviation-in-array/discuss/952776/python-simple-priority-queue-solution

class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    vector<int> nums2 = nums;
    int n = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
        pq;  // val, idx
    int mx = INT32_MIN;
    for (int i = 0; i < n; ++i) {
      while ((nums2[i] & 1) == 0) {
        nums2[i] >>= 1;
      }
      if (nums[i] & 1) nums[i] *= 2;
      mx = max(mx, nums2[i]);
      pq.emplace(nums2[i], i);
    }

    int res = INT32_MAX;
    int mn;
    while (!pq.empty()) {
      auto p = pq.top();
      mn = p.first;
      res = min(res, mx - mn);
      pq.pop();
      if (p.first < nums[p.second]) {
        p.first <<= 1;
        mx = max(mx, p.first);
        pq.push(p);
      } else {
        break;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  cout << s.minimumDeviation(nums) << endl;
  return 0;
}
