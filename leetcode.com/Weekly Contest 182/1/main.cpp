#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLucky(vector<int>& arr) {
    unordered_map<int, int> m;
    for (int i : arr) m[i]++;
    int res = -1;
    for (auto& p : m) {
      if (p.second == p.first && p.first > res) {
        res = p.first;
      }
    }
    return res;
  }
};