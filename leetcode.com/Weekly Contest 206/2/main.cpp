#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int res = 0;
        vector<int> pr(n);
        for (auto &pair: pairs) {
          pr[pair[0]] = pair[1];
          pr[pair[1]] = pair[0];
        }
        vector<vector<int>> ranks(n, vector<int>(n));
        for (int i=0; i < n; ++i) {
          int r = 0;
          for (int person: preferences[i]) {
            ranks[i][person] =++r;
          }
        }
        for (int x = 0; x < n; ++x) {
          for (int u = 0; u < n; ++u) { // chk j
            if (u == x || u == pr[x] || ranks[x][u] > ranks[x][pr[x]]) continue;
            if (ranks[u][x] < ranks[u][pr[u]]) {
              ++res;
              break;
            }
          }
        }
        return res;
    }
};
