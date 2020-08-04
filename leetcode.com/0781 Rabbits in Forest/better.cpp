#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/rabbits-in-forest/discuss/114721/C%2B%2BJavaPython-Easy-and-Concise-Solution

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    vector<int> cnts(1000);
    int res = 0;
    for (int ans : answers) {
      if (cnts[ans]++ % (ans + 1) == 0) res += ans + 1;
    }
    return res;
  }
};
