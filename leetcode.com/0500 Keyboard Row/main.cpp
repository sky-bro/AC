#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    uint8_t rows[128]{};
    for (char c : "QWERTYUIOP") rows[c] = rows[c + 32] = 1;
    for (char c : "ASDFGHJKL") rows[c] = rows[c + 32] = 2;
    for (char c : "ZXCVBNM") rows[c] = rows[c + 32] = 3;
    vector<string> res;
    for (string& word : words) {
      uint8_t row = rows[word[0]];
      if (all_of(word.begin(), word.end(),
                 [&rows, row](char c) { return rows[c] == row; }))
        res.push_back(word);
    }
    return res;
  }
};