#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isTransformable(string s, string t) {
    vector<int> cntS(10), cntT(10);
    vector<vector<int>> smallerS(10), smallerT(10);
    for (char c : s) {
      cntS[c - '0']++;
      smallerS[c - '0'].push_back(
          accumulate(cntS.begin(), cntS.begin() + (c - '0'), 0));
    }
    for (char c : t) {
      cntT[c - '0']++;
      smallerT[c - '0'].push_back(
          accumulate(cntT.begin(), cntT.begin() + (c - '0'), 0));
    }
    for (int i = 0; i < 10; ++i)
      if (cntS[i] != cntT[i]) return false;
    for (int i = 0; i < 10; ++i) {
      for (int j = smallerS[i].size() - 1; j >= 0; --j) {
        if (smallerS[i][j] > smallerT[i][j]) return false;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) {
  string s, t;
  Solution sol;
  while (cin >> s >> t) {
    cout << sol.isTransformable(s, t) << endl;
  }
  return 0;
}
