#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
      vector<int> cnts(1000);
      for (int ans: answers) {
        ++cnts[ans];
      }
      int res = 0;
      for (int i = 0; i < 1000; ++i) {
        res += (cnts[i] + i) / (i+1) * (i + 1);
      }
      return res;
    }
};
