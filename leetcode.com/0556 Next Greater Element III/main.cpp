#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int nextGreaterElement(int n) {
    string s = to_string(n);
    bool is_bigger = next_permutation(s.begin(), s.end());
    long long res = stoll(s);
    return is_bigger && res <= INT32_MAX ? res : -1;
  }
};