#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestTimeFromDigits(vector<int>& arr) {
    string s = "HH:MM";
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < 4; ++i) {
      if (arr[i] > 2) continue;
      s[0] = arr[i] + '0';
      for (int j = 0; j < 4; ++j) {
        int h = arr[i] * 10 + arr[j];
        if (h > 23 || i == j) continue;
        s[1] = arr[j] + '0';
        for (int p = 0; p < 4; ++p) {
          if (p == i || p == j || arr[p] > 5) continue;
          s[3] = arr[p] + '0';
          for (int q = 0; q < 4; ++q) {
            if (q == i || q == j || q == p) continue;
            s[4] = arr[q] + '0';
            return s;
          }
        }
      }
    }
    return "";
  }
};