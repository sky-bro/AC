#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int m[26]{0};
    for (char c : magazine) {
      m[c - 'a']++;
    }
    for (char c : ransomNote) {
      if (m[c - 'a'] == 0) return false;
      m[c - 'a']--;
    }
    return true;
  }
};