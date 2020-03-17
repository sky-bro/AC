#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int res;
  // r-m <= m+1-l
  void _merge(vector<int> &nums, int l, int m, int r) {
    int i = l, j = m + 1;
    for (; i <= m && j <= r; ++i) {
      while (j <= r && nums[i] > 2LL * nums[j]) ++j;
      res += j - m - 1;
    }
    res += (m + 1 - i) * (j - m - 1);
    vector<int> tmp;
    for (i = l, j = m + 1; i <= m && j <= r;) {
      if (nums[i] < nums[j])
        tmp.push_back(nums[i++]);
      else
        tmp.push_back(nums[j++]);
    }
    while (i <= m) tmp.push_back(nums[i++]);
    while (j <= r) tmp.push_back(nums[j++]);
    copy(tmp.begin(), tmp.end(), nums.begin() + l);
  }

  void _mergeSort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    _mergeSort(nums, l, m);
    _mergeSort(nums, m + 1, r);
    _merge(nums, l, m, r);
  }

 public:
  int reversePairs(vector<int> &nums) {
    res = 0;
    _mergeSort(nums, 0, nums.size() - 1);
    return res;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) {
    cout << t << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {1, 3, 2, 3, 1};  // 2
  nums = {2, 4, 3, 5, 1};              // 3
  cout << s.reversePairs(nums) << endl;
  printArr(nums);
  return 0;
}
