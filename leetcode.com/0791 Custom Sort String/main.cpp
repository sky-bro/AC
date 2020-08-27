#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string customSortString(string S, string T) {
    vector<int> cnts(26);
    for (char c : T) cnts[c - 'a']++;
    string res = "";
    for (char c : S) {
      while (cnts[c - 'a']) {
        res.push_back(c);
        --cnts[c - 'a'];
      }
    }
    for (int i = 0; i < 26; ++i) {
      while (cnts[i]) {
        res.push_back(i + 'a');
        --cnts[i];
      }
    }
    return res;
  }
};
