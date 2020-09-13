#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 最小生成树

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n= points.size();
    int res = 0;
    vector<vector<int>> G(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i ==j)continue;
        G[i][j] = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
      }
    }
    vector<pair<int,int>> costs(n);
    costs[0] = {0, 0};
    for (int i= 1; i < n; ++i) {
      costs[i] = {0,  G[0][i]};
    }

    for (int e = 1 ; e < n; ++e) {
      int k = -1, cost = INT32_MAX;

      for (int j = 0; j < n; ++j) {
        if (costs[j].second && costs[j].second < cost) {
          cost = costs[j].second;
          k=j;
        }
      }
      res += costs[k].second;
      costs[k].second = 0;
      for (int j = 0; j  < n; ++j) {
        if (G[k][j] < costs[j].second) {
          costs[j].first = k;
          costs[j].second = G[k][j];
        }
      }
    }
    return res;
  }
};
