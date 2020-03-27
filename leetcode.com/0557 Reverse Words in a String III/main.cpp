#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    istringstream ISS(s);
    vector<string> vs;
    string t, res;
    ISS >> res;
    reverse(res.begin(), res.end());
    while (ISS >> t) {
      res.push_back(' ');
      reverse(t.begin(), t.end());
      res.append(t);
    }
    return res;
  }
};