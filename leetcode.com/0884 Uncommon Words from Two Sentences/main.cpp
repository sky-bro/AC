#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> uncommonFromSentences(string A, string B) {
    istringstream ISS_A(A), ISS_B(B);
    string s;
    unordered_map<string, int> a, b;
    while (ISS_A >> s) {
      a[s]++;
    }
    while (ISS_B >> s) {
      b[s]++;
    }
    vector<string> res;
    for (auto &p : a) {
      if (p.second > 1 || b.count(p.first)) continue;
      res.push_back(p.first);
    }
    for (auto &p : b) {
      if (p.second > 1 || a.count(p.first)) continue;
      res.push_back(p.first);
    }
    return res;
  }
};
