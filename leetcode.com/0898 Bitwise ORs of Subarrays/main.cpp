#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& arr) {
    vector<int> d;
    int l = 0, r;
    for (int i : arr) {
      r = d.size();
      d.push_back(i);
      for (; l < r; ++l) {
        int x = d[l] | i;
        if (x != d.back()) {  // x >= d.back()
          d.push_back(x);
        }
      }
    }
    return unordered_set<int>(d.begin(), d.end()).size();
  }
};
