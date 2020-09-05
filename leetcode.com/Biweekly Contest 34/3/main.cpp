#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    int res = n;
    int len = 1, i = 1, j = n - 2;
    for (; i < n && arr[i] >= arr[i - 1]; ++i, ++len)
      ;
    if (len == n) return 0;
    res = n - len;
    len = 1;
    for (; j >= 0 && arr[j] <= arr[j + 1]; --j, ++len)
      ;
    res = min(res, n - len);

    --i;
    ++j;
    int jj = j;
    for (; j < n && arr[j] < arr[i]; ++j)
      ;
    len = n - j + i + 1;
    res = min(res, n - len);
    for (--i; i >= 0 && j > jj; --i) {
      for (; j > jj && arr[j - 1] >= arr[i]; --j)
        ;
      len = n - j + i + 1;
      res = min(res, n - len);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
  arr = {1};
  arr = {1, 2, 3};
  arr = {5, 4, 3, 2, 1};
  Solution s;
  cout << s.findLengthOfShortestSubarray(arr) << endl;

  return 0;
}
