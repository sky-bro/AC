#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  unordered_map<string, int> mp;

 public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    mp.clear();
    for (string d : cpdomains) {
      istringstream ISS(d);
      int cnt;
      ISS >> cnt;
      ISS >> d;
      mp[d] += cnt;
      int n = d.size(), i = 0;
      while (1) {
        while (i < n && d[i] != '.') ++i;
        if (++i > n) break;
        string td = d.substr(i);
        mp[td] += cnt;
      }
    }
    vector<string> res;
    for (auto& p : mp) {
      res.push_back(to_string(p.second) + " " + p.first);
    }
    return res;
  }
};
