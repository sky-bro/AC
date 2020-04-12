// ref: O(nlogn) and O(n) algo
// https://leetcode.com/problems/last-stone-weight/discuss/360024/O(nlogn)-and-O(n)-algo
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// use bucket sort
class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    int m = *max_element(stones.begin(), stones.end());
    vector<int> bucket(m + 1);
    for (int stone : stones) ++bucket[m];
    int i = m, lastJ = m;
    while (i) {
      if (bucket[i] == 0) {
        --i;
        continue;
      }

      if (bucket[i] & 1 == 0) {  // smash with myself
        --i;
        continue;
      }

      // smash myself, then one stone of weight i left
      int j = min(lastJ, i - 1); // very clever to use lastJ
      while (j && bucket[j] == 0) --j;
      if (j == 0) return i; // this is the last stone, return

      lastJ = j;
      --bucket[j];
      ++bucket[i - j];
      if (i - j > j) {
        i = i - j;
      } else {
        i = j;
      }
    }
    return 0;
  }
};
