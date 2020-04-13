#include <iostream>
#include <vector>

using namespace std;

// kmp
class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    int lenA = A.length(), lenB = B.length();
    vector<int> tr(lenB);
    for (int i = 1, len = 0; i < lenB;) {
      if (B[i] == B[len])
        tr[i++] = ++len;
      else if (len == 0)
        tr[i++] = 0;
      else
        len = tr[len - 1];
    }
    for (int i = 0, j = 0; i - j < lenA;) {
      while (j < lenB && A[i % lenA] == B[j]) {
        ++i;
        ++j;
      }
      if (j == lenB) {  // found match
        int res = i / lenA;
        if (lenA * res != i) ++res;
        return res;
      }
      // not found
      if (j == 0)
        ++i;
      else {
        j = tr[j - 1];
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string A, B;
  while (cin >> A >> B) {
    cout << s.repeatedStringMatch(A, B) << endl;
  }
  return 0;
}
