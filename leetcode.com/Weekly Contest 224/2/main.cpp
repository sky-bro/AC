#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int tupleSameProduct(vector<int>& A) {
    int res = 0, n = A.size();
    map<int, int> mp;
    for (int i = (0); i < A.size(); i++) {
      for (int j = i + 1; j < A.size(); j++) {
        res += mp[A[i] * A[j]]++;
      }
    }
    return res * 8;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> v = {2, 3, 4, 6};
  v = {1, 2, 4, 5, 10};
  v = {20, 10, 6, 24, 15, 5, 4, 30};
  cout << s.tupleSameProduct(v) << endl;
  return 0;
}
