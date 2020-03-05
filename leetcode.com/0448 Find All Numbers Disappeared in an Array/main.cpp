#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] > 0) nums[idx] *= -1;
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) res.push_back(i + 1);
    }
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
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};  // {5, 6}
  printArr(s.findDisappearedNumbers(nums));
  return 0;
}
