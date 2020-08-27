#include <iostream>
#include <vector>

using namespace std;

// ref: Efficient and simple, go through words in parallel, with explanation
// https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation

class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    vector<pair<int, int>> waiting[128];
    for (int i = 0; i < words.size(); i++)
      waiting[words[i][0]].emplace_back(i, 1);
    for (char c : S) {
      auto advance = waiting[c];
      waiting[c].clear();
      for (auto it : advance)
        waiting[words[it.first][it.second++]].push_back(it);
    }
    return waiting[0].size();
  }
};
