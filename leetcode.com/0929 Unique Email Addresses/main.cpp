#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_map<string, unordered_set<string>> m;
    for (const string& e : emails) {
      string domain = e.substr(e.find('@'));
      string name;
      for (char c : e) {
        if (c == '@' || c == '+') break;
        if (c == '.') continue;
        name.push_back(c);
      }
      m[domain].insert(name);
    }
    int res = 0;
    for (auto& s : m) {
      res += s.second.size();
    }
    return res;
  }
};
