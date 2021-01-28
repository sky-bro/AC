#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n, INT32_MAX);
    int arr[] = {1, 7, 30};
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < 3; ++j) {
        auto it =
            lower_bound(days.begin() + i + 1, days.end(), days[i] + arr[j]);
        int pre = (it != days.end()) ? dp[it - days.begin()] : 0;
        dp[i] = min(dp[i], costs[j] + pre);
      }
    }
    return dp[0];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15}; // 11
  days = {1,2,3,4,5,6,7,8,9,10,30,31}; // 17
  cout << s.mincostTickets(days, costs) << endl;
  return 0;
}
