#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    stable_sort(logs.begin(), logs.end(), [](const string &a, const string &b) {
      int i1 = a.find(' '), i2 = b.find(' ');
      bool b1 = isdigit(a[i1 + 1]), b2 = isdigit(b[i2 + 1]);
      if (b1) {
        return false;
      } else if (b2) {
        return true;
      } else {
        return (a.substr(i1 + 1) == b.substr(i2 + 1))
                   ? (a.substr(0, i1) < b.substr(0, i2))
                   : (a.substr(i1 + 1) < b.substr(i2 + 1));
      }
    });
    return logs;
  }
};
