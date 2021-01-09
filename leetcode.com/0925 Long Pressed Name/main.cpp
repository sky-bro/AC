#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int n1 = name.size(), n2 = typed.size();
    if (n1 > n2)
      return false;
    else if (n1 == n2)
      return name == typed;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
      if (name[i] != typed[j]) return false;
      int ii = i + 1, jj = j + 1;
      while (name[ii] == name[i]) ++ii;
      while (typed[jj] == typed[j]) ++jj;
      if (jj - j < ii - i) return false;
      i = ii;
      j = jj;
    }
    return i == n1 && j == n2;
  }
};
