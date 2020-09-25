#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    int i = S.size() - 1, j = T.size() - 1;
    while (i >= 0 || j >= 0) {
      char s = 0, t = 0;
      if (i != -1) {
        int back_space = 0;
        while (S[i] == '#' || back_space) {
          if (S[i] == '#')
            ++back_space;
          else
            --back_space;
          if (--i < 0) break;
        }
        if (i != -1) s = S[i];
      }
      if (j != -1) {
        int back_space = 0;
        while (T[j] == '#' || back_space) {
          if (T[j] == '#')
            ++back_space;
          else
            --back_space;
          if (--j < 0) break;
        }
        if (j != -1) t = T[j];
      }
      if (s != t) return false;
      if (s) --i;
      if (t) --j;
    }
    return i == j;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string S = "bbbextm";
  string T = "bbb#extm";

  cout << s.backspaceCompare(S, T) << endl;
  return 0;
}
