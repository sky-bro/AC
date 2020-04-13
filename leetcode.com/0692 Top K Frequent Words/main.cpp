#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> m;
    for (string& word : words) ++m[word];
    vector<pair<string, int>> vp(m.begin(), m.end());
    // you may use nth_element first, then sort the top k elements
    sort(vp.begin(), vp.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
           if (a.second == b.second) return a.first < b.first;
           return a.second > b.second;
         });
    vector<string> res;
    for (int i = 0; i < k; ++i) {
      res.push_back(vp[i].first);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> words = {"a", "aa", "aaa"};
  int k = 1;
  printArr(s.topKFrequent(words, k));
  return 0;
}
