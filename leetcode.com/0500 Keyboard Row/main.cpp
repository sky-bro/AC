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
    copy_if(words.begin(), words.end(), back_inserter(res), [&](string& word) {
      uint8_t row = rows[word[0]];
      return all_of(word.begin(), word.end(),
                    [&](char c) { return rows[c] == row; });
    });
    return res;
  }
};