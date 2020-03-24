#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int to_min(string TP) {
    int h = 0, m = 0, i = 0;

    for (; TP[i] != ':'; ++i) h = h * 10 + TP[i] - '0';
    for (++i; i < TP.length(); ++i) m = m * 10 + TP[i] - '0';

    return h * 60 + m;
  }

 public:
  int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    vector<int> tps;
    for (string& tp : timePoints) {
      tps.push_back(to_min(tp));
    }
    sort(tps.begin(), tps.end());
    tps.push_back(tps[0] + 60 * 24);
    int res = 60 * 24;
    for (int i = 1; i <= n; ++i) {
      res = min(res, tps[i] - tps[i - 1]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> tps = {"23:59", "00:00"};
  cout << s.findMinDifference(tps) << endl;
  return 0;
}
