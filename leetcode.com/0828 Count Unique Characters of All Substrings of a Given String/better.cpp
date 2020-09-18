#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/128952/C%2B%2BJavaPython-One-pass-O(N)

/*

Think about string "XAXAXXAX" and focus on making the second "A" a unique
character. We can take "XA(XAXX)AX" and between "()" is our substring. We can
see here, to make the second "A" counted as a uniq character, we need to:

  1. insert "(" somewhere between the first and second A
  2. insert ")" somewhere between the second and third A

For step 1 we have "A(XA" and "AX(A", 2 possibility.
For step 2 we have "A)XXA", "AX)XA" and "AXX)A", 3 possibilities.

So there are in total 2 * 3 = 6 ways to make the second A a unique character in
a substring. In other words, there are only 6 substring, in which this A
contribute 1 point as unique string.

Instead of counting all unique characters and struggling with all possible
substrings, we can count for every char in S, how many ways to be found as a
unique char. We count and sum, and it will be out answer.

*/

class Solution {
 public:
  int uniqueLetterString(string S) {
    int index[26][2], res = 0, N = S.length(), mod = pow(10, 9) + 7;
    memset(index, -1, sizeof(int) * 52);
    for (int i = 0; i < N; ++i) {
      int c = S[i] - 'A';
      res = (res + (i - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
      index[c][0] = index[c][1];
      index[c][1] = i;
    }
    for (int c = 0; c < 26; ++c)
      res = (res + (N - index[c][1]) * (index[c][1] - index[c][0]) % mod) % mod;
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  string str = "ABA";  // 6
  str = "ABC";         // 10
  str = "LEETCODE";    // 92
  while (cin >> str) {
    cout << s.uniqueLetterString(str) << endl;
  }
  return 0;
}
