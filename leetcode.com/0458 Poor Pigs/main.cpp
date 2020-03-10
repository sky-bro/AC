#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int T = minutesToTest / minutesToDie;
    return ceil(log(buckets) / log(T + 1));
  }
};