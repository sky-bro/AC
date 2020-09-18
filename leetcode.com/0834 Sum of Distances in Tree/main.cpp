#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int N;
  vector<vector<int>> G0;
  vector<vector<int>> G;
  vector<int> node_cnt;   // number of nodes of a subtree
  vector<int> node_dist;  // sum of dists from a node to its children

  // build tree
  void dfs0(int node, vector<bool>& vis) {
    vis[node] = true;
    for (int next_node : G0[node]) {
      if (vis[next_node]) continue;
      G[node].push_back(next_node);
      dfs0(next_node, vis);
    }
  }

  void dfs(int node) {
    node_cnt[node] = 1;
    // node_dist[node] = 0;
    for (int next_node : G[node]) {
      dfs(next_node);
      node_cnt[node] += node_cnt[next_node];
      node_dist[node] += node_dist[next_node] + node_cnt[next_node];
    }
  }

  void dfs2(int node) {
    for (int next_node : G[node]) {
      node_dist[next_node] = node_dist[node] + (N - node_cnt[next_node] * 2);
      dfs2(next_node);
    }
  }

 public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    this->N = N;
    G0.clear();
    G0.resize(N);
    G.clear();
    G.resize(N);
    node_cnt.clear();
    node_cnt.resize(N);
    node_dist.clear();
    node_dist.resize(N);

    for (auto& edge : edges) {
      G0[edge[0]].push_back(edge[1]);
      G0[edge[1]].push_back(edge[0]);
    }
    vector<bool> vis(N);
    dfs0(0, vis);
    dfs(0);
    dfs2(0);
    return node_dist;
  }
};
