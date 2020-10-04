#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    int n = keyName.size();
    map<string, set<int>> m;
    for (int i = 0; i < n; ++i) {
      int j = keyTime[i].find(':');
      int t =
          stoi(keyTime[i].substr(0, j)) * 60 + stoi(keyTime[i].substr(j + 1));
      m[keyName[i]].insert(t);
    }
    vector<string> res;
    for (auto& p : m) {
      if (p.second.size() >= 3) {
        auto it = p.second.begin();
        auto it2 = it;
        ++it2;
        ++it2;
        while (it2 != p.second.end()) {
          if ((*it2) - (*it) <= 60) {
            res.push_back(p.first);
            break;
          }
          ++it;
          ++it2;
        }
      }
    }
    return res;
  }
};
