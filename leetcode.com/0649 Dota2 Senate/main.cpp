#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/dota2-senate/discuss/105860/C++-O(n)-solution/108334

// I think this solution is very tricky
// we only append 'D' or 'R' when we meet its conterpart ('R' or 'D')

class Solution {
 public:
  string predictPartyVictory(string senate) {
    int cnt = 0;
    for (int i = 0; i < senate.size(); ++i) {
      if (senate[i] == 'R') {
        if (++cnt <= 0) senate.push_back('D');
      } else {
        if (--cnt >= 0) senate.push_back('R');
      }
    }
    return cnt > 0 ? "Radiant" : "Dire";
  }
};