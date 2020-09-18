#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string s) {
    set<vector<int>> st;
    for (int i = s.length() - 1; i >= 0;) {
      int j = i;
      while (j >= 0 && s[j] == s[i]) --j;
      if (i - j >= 3) st.insert({j + 1, i});
      i = j;
    }
    return vector<vector<int>>(st.begin(), st.end());
  }
};
