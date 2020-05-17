#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
      text[0] = tolower(text[0]);
      istringstream ISS(text);
      vector<string> words;
      string word;
      while (ISS>>word) words.push_back(word);
      stable_sort(words.begin(), words.end(), [](const string &a, const string &b){
        return a.length() < b.length();
      });
      string res = words[0];
      res[0] = toupper(res[0]);
      for (int i = 1; i < words.size(); ++i) {
        res.push_back(' ');
        res.append(words[i]);
      }
      return res;
    }
};
