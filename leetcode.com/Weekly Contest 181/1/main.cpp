#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> createTargetArray(vector<int> &nums, vector<int> &index) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      res.insert(res.begin() + index[i], nums[i]);
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
  vector<int> nums = {0, 1, 2, 3, 4};
  vector<int> index = {0, 1, 2, 2, 1};
  printArr(s.createTargetArray(nums, index));
  return 0;
}
