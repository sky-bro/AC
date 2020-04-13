#include <iostream>
#include <vector>

using namespace std;

// brute force
class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    int lenA = A.length(), lenB = B.length();
    for (int i = 0; i < lenA; ++i) {
      int j = 0;
      while (j < lenB && A[(i + j) % lenA] == B[j]) ++j;
      if (j == lenB) {
        int res = (lenB + i) / lenA;
        if (lenA * res != lenB + i) ++res;
        return res;
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  // A: baba B: aba
  // A repeat 1 time or 2 times, we can find B in it: b(aba), bab(aba)ba
  // once we find a match (from left to right),
  // that's what we need (minimum repeat times: 1 here for this example)
  Solution s;
  string A, B;
  while (cin >> A >> B) {
    cout << s.repeatedStringMatch(A, B) << endl;
  }
  return 0;
}
