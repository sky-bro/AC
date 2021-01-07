#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string reverseOnlyLetters(string S) {
    for (int i = 0, j = S.length(); i < j; ++i, --j) {
      while (i < j && !isalpha(S[i])) ++i;
      while (i < j && !isalpha(S[j])) --j;
      if (i < j)
        swap(S[i], S[j]);
      else
        break;
    }
    return S;
  }
};
