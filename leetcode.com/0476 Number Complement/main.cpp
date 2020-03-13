#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findComplement(int num) {
    int i = 0, bak = num;
    for (; num; ++i) num >>= 1;
    return bak ^ ((1 << i) - 1u);
  }
};

class Solution2 {
 public:
  int findComplement(int num) {
    unsigned mask = ~0;
    while (mask & num) mask <<= 1;
    return ~mask ^ num;
  }
};