#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    int t[26];
    for (int i = 0; i < 26; ++i) t[order[i] - 'a'] = i;
    return is_sorted(words.begin(), words.end(), [&t](const string&a, const string&b){
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (t[a[i]-'a'] < t[b[i]-'a']) return true;
            else if (t[a[i]-'a'] > t[b[i]-'a']) return false;
        }
        return a.size() < b.size();
    });
  }
};
