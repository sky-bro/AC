#include <iostream>
#include <vector>

using namespace std;

// greedy I think

class Solution {
 public:
  bool canConstruct(string s, int k) {
    int n = s.length();
    if (k > n) return false; // corner case (need non-empty)
    bool is_odd[26]{};
    for (char c : s) is_odd[c - 'a'] ^= true;
    int odd_cnt = 0;
    for (int i = 0; i < 26; ++i) {
      odd_cnt += is_odd[i];
    }
    // odd chars must each in a separate palindrome
    // (say we only use one of each these odd chars, all left will be used to build remaining palindromes)
    k -= odd_cnt; 
    if (k < 0) return false; // not enough palindrome to put odd chars
    // cnt of remaining chars >= number of remaining palindromes
    return true; // always can build remaining palindromes
  }
};