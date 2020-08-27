#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// jump table (next_index): next index of char a is at *next_index[idx+1]['a']
// this sol is time & spaced expensive... see better.cpp
class Solution {
 private:
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    vector<int*> pointers;
    vector<int*> cur_pointers(26);
    for (int i = 0; i < 26; ++i) {
      cur_pointers[i] = new int(-1);
      pointers.push_back(cur_pointers[i]);
    }
    int n = S.length();
    vector<vector<int*>> next_index(n + 1, vector<int*>(26));
    for (int i = 0; i < 26; ++i) next_index[0][i] = cur_pointers[i];
    for (int i = 0; i < n; ++i) {
      *cur_pointers[S[i] - 'a'] = i;
      for (int j = 0; j < 26; ++j) {
        next_index[i][j] = cur_pointers[j];
      }
      cur_pointers[S[i] - 'a'] = new int(-1);
      pointers.push_back(cur_pointers[S[i] - 'a']);
    }
    for (int i = 0; i < 26; ++i) next_index[n][i] = cur_pointers[i];
    auto chk = [&next_index](const string& word) {
      int idx = -1;
      for (char c : word) {
        if ((idx = *next_index[idx + 1][c - 'a']) == -1) return false;
      }
      return true;
    };
    int res = count_if(words.begin(), words.end(), chk);
    for (int* pointer : pointers) delete pointer;
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string S = "abcde";
  vector<string> words = {"a", "bb", "acd", "ace"};
  cout << s.numMatchingSubseq(S, words) << endl;
  return 0;
}
