#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

static string CODES[] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                         "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                         "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                         "...-", ".--",  "-..-", "-.--", "--.."};

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> st;
    for (const string &word: words) {
      string str = "";
      for (char c: word) {
        str.append(CODES[c-'a']);
      }
      st.insert(str);
    }
    return st.size();
  }
};
