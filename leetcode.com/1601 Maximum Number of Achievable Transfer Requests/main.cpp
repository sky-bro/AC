#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int res;
  int len;
  /**
   * @param state each bit i of state represents if build i's net change of
   * transfer employees is 0. 0 means net change is 0, 1 means not.
   */
  void dfs(bitset<20> state, int i, int cur_res, vector<int>& diff_cnts,
           vector<vector<int>>& reqs) {
    if (i == len) {
      if (state.none()) res = max(res, cur_res);
      return;
    }
    // req not taken
    dfs(state, i + 1, cur_res, diff_cnts, reqs);
    // req taken
    diff_cnts[reqs[i][0]]--;
    diff_cnts[reqs[i][1]]++;
    if (diff_cnts[reqs[i][0]] == 0) {
      state[reqs[i][0]] = 0;
    } else if (diff_cnts[reqs[i][0]] == -1) {
      state[reqs[i][0]] = 1;
    }

    if (diff_cnts[reqs[i][1]] == 0) {
      state[reqs[i][1]] = 0;
    } else if (diff_cnts[reqs[i][1]] == 1) {
      state[reqs[i][1]] = 1;
    }
    dfs(state, i + 1, cur_res + 1, diff_cnts, reqs);
    // restore
    diff_cnts[reqs[i][0]]++;
    diff_cnts[reqs[i][1]]--;
  }

 public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    len = requests.size();
    res = 0;
    vector<int> diff_cnts(n);
    bitset<20> state;
    dfs(state, 0, 0, diff_cnts, requests);
    return res;
  }
};
