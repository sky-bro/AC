#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  string dfs(vector<string>& dp, vector<int>& cost, int target) {
    if (!dp[target].empty()) return dp[target];
    string res = "0", cur;
    for (int i = 0; i < 9; ++i) {
      int ntarget = target - cost[i];
      if (ntarget < 0) continue;
      string cur_num = to_string(i+1);
      if (ntarget == 0) {
        if (res.size() == 1 && res[0] < cur_num[0]) res = cur_num;
        continue;
      }
      cur = dfs(dp, cost, ntarget);
      if (cur != "0") cur = cur_num + cur; else continue;
      if (cur.size() >= res.size() && cur > res) res = cur;
    }
    return dp[target]=res;
  }
public:
    string largestNumber(vector<int>& cost, int target) {
      vector<string> dp(target+1);
      return dfs(dp, cost, target);
    }
};


int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> cost = {4,3,2,5,6,7,2,5,5};
  int target = 9;
  cout<<s.largestNumber(cost, target)<<endl;
  return 0;
}
