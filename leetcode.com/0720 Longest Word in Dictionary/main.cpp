#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// ref: [Java/C++] Clean Code
// https://leetcode.com/problems/longest-word-in-dictionary/discuss/109114/JavaC%2B%2B-Clean-Code

class Solution {
 public:
  string longestWord(vector<string>& words) {
    sort(words.begin(), words.end());
    unordered_set<string> built;
    string res;
    for (string w : words) {
      if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
        res = w.size() > res.size() ? w : res;
        built.insert(w);
      }
    }
    return res;
  }
};
