#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return false;
    int i = 1;
    while (i < n) {
      if (arr[i] < arr[i - 1]) {
        break;
      } else if (arr[i] == arr[i - 1])
        return false;
      ++i;
    }
    if (i == 1 || i == n) return false;
    ++i;
    while (i < n) {
      if (arr[i] >= arr[i - 1]) return false;
      ++i;
    }
    return true;
  }
};
