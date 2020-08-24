#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * compute shortest distance from src to all other nodes
 */
void dijkstra(const vector<unordered_map<int, int>>& G, int src,
              vector<int>& dist) {
  int n = G.size();
  dist.clear();
  dist.resize(n, -1);
  vector<bool> vis(n);
  priority_queue<pair<int, int>> pq;  // {-weight, label}
  pq.emplace(0, src);
  dist[src] = 0;
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    vis[p.second] = true;
    for (auto neighbor : G[p.second]) {
      int v = neighbor.first;
      int d = neighbor.second - p.first;
      if (vis[neighbor.first]) continue;
      if (dist[v] == -1 || dist[v] > d) {
        pq.emplace(-d, v);
        dist[v] = d;
      }
    }
  }
}

template <typename T>
void printArr(const vector<T>& arr) {
  for (const T& t : arr) cout << t << " ";
  cout << endl;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> edges = {
      {0, 1, 100}, {1, 2, 100}, {0, 2, 500}};  // {src, dst, weight}, ...
  vector<unordered_map<int, int>> G(edges.size());
  for (const auto& edge : edges) {
    G[edge[0]][edge[1]] = edge[2];
  }
  vector<int> dist;
  int src = 0;
  dijkstra(G, src, dist);
  printArr(dist);
  return 0;
}
