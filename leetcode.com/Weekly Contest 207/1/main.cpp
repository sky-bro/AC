#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
 public:
  string reorderSpaces(string text) {
    istringstream ISS(text);
    vector<string> words;
    string word;
    while (ISS >> word) words.push_back(word);
    int cnts = 0;
    for (char c : text)
      if (c == ' ') ++cnts;
    int n = words.size();
    string res = words[0];
    if (n == 1) {
      for (int i = 0; i < cnts; ++i) res.push_back(' ');
      return res;
    }
    int len = cnts / (n - 1), r = cnts % (n - 1);
    string spaces = "";
    for (int i = 0; i < len; ++i) spaces.push_back(' ');
    for (int i = 1; i < n; ++i) {
      res += spaces + words[i];
    }
    for (int i = 0; i < r; ++i) res.push_back(' ');
    return res;
  }
};
