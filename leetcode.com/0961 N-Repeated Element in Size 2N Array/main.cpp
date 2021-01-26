#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    vector<int> cnts(10000);
    for (int a : A) {
      if (cnts[a]++) return a;
    }
    return -1;
  }
};
