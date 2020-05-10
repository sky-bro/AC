#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// ref: Simple Java O(n) Solution with detailed explanation
// https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/113528/Simple-Java-O(n)-Solution-with-detailed-explanation

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      int res = 1, max_val = 0;
      for (int i = 0; i < n-1; ++i) {
        max_val = max(max_val, arr[i]);
        if (max_val == i) ++res;
      }
      return res;
    }
};

