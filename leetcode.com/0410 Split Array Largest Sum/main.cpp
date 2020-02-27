#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int m, n;
  bool check(long long mid, vector<int>& nums) {
    int i = 0;
    for (int cnt = 0; i < n && cnt < m; ++cnt)
      for (long long sum = nums[i++]; i < n && sum + nums[i] <= mid;
           sum += nums[i++])
        ;
    return i == n;
  }

 public:
  int splitArray(vector<int>& nums, int m) {
    // initiations
    this->m = m;
    n = nums.size();
    long long hi = 0, lo = 0;
    for (long long i : nums) {
      lo = max(i, lo);
      hi += i;
    }
    lo = max(lo, hi / m);

    // binary search
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (check(mid, nums)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    // done
    return lo;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {7, 2, 5, 10, 8};
  nums = {1, 2147483647};
  cout << s.splitArray(nums, 2) << endl;
  return 0;
}
