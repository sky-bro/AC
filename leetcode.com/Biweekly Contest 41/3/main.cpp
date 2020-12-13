#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    int n = aliceValues.size();
    if (n == 1) return 1;
    // priority_queue<pair<int, int>> pq;
    map<int, multiset<int>> mp;
    for (int i = 0; i < n; ++i) {
      mp[aliceValues[i] + bobValues[i]].insert(aliceValues[i]);
    }
    int aS = 0, bS = 0;
    bool isA = 1;
    for (auto it = mp.rbegin(); it != mp.rend(); isA = !isA) {
      if (it->second.size() > 1) {
        if (isA) {
          auto iit = it->second.rbegin();
          aS += *iit;
          it->second.erase(next(iit).base());
          //   it->second.erase(it->second.find(*iit));

        } else {
          auto iit = it->second.begin();
          bS += it->first - *iit;
          it->second.erase(iit);
        }
      } else {
        if (isA) {
          aS += *it->second.begin();
        } else {
          bS += it->first - *it->second.begin();
        }
        ++it;
      }
    }
    return aS == bS ? 0 : (aS > bS ? 1 : -1);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {1, 3};
  vector<int> B = {2, 1};
  cout << s.stoneGameVI(A, B) << endl;
  return 0;
}
