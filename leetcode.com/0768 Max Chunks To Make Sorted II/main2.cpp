#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ref: [C++] 9 lines, 15ms
// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/discuss/113464/C%2B%2B-9-lines-15ms

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      long long sum1 = 0, sum2 = 0, ans = 0;
      vector<int> t = arr;
      sort(t.begin(), t.end());
      for(int i = 0; i < arr.size(); i++) {
          sum1 += t[i];
          sum2 += arr[i];
          if(sum1 == sum2) ans++;
      }
      return ans;
    }
};
