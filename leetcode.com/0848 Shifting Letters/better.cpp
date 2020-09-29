#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string shiftingLetters(string S, vector<int>& shifts) {
    for (int i = shifts.size() - 1, m = 0; i >= 0; m = (m + shifts[i--]) % 26) {
      S[i] = (S[i] - 'a' + m + shifts[i]) % 26 + 'a';
    }
    return S;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string S = "abc";
  vector<int> shifts = {3, 5, 9};
  cout << s.shiftingLetters(S, shifts) << endl;
  return 0;
}
