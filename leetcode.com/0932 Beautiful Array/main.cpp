#include <iostream>
#include <vector>

using namespace std;

// strong trick, math
// https://leetcode.com/problems/beautiful-array/discuss/186679/
class Solution {
 public:
  vector<int> beautifulArray(int N) {
    vector<int> res = {1};
    while (res.size() < N) {
      vector<int> tmp;
      for (int i : res)
        if (i * 2 - 1 <= N) tmp.emplace_back(i * 2 - 1);
      for (int i : res)
        if (i * 2 <= N) tmp.emplace_back(i * 2);
      res = tmp;
    }
    return res;
  }
};
