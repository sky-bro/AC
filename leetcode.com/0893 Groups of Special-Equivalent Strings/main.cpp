#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSpecialEquivGroups(vector<string>& A) {
    map<pair<vector<int>, vector<int>>, int> mp;
    int n = A[0].size();
    for (const string& a : A) {
      pair<vector<int>, vector<int>> p = {vector<int>(26), vector<int>(26)};
      bool first = true;
      for (char c : a) {
        if ((first = !first)) {
          p.first[c - 'a']++;
        } else {
          p.second[c - 'a']++;
        }
      }
      mp[p]++;
    }
    return mp.size();
  }
};
