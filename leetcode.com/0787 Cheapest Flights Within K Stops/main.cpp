#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    vector<map<int, int>> dist(n);  // k: dist
    vector<unordered_map<int, int>> G(n);
    for (const auto& flight : flights) {
      G[flight[0]][flight[1]] = flight[2];
    }
    priority_queue<array<int, 3>> pq;  // -dist, label, k
    pq.push({0, src, -1});
    dist[src][-1] = 0;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      if (p[1] == dst) return -p[0];
      if (p[2] == K) continue;
      for (auto neighbor : G[p[1]]) {
        if (p[2] == K && p[1] != dst) continue;
        int cur_dist = -p[0] + neighbor.second;
        if (dist[neighbor.first].find(p[2]) == dist[neighbor.first].end() ||
            dist[neighbor.first][p[2]] >= cur_dist) {
          dist[neighbor.first][p[2]] = cur_dist;
        } else {
          continue;
        }
        pq.push({-cur_dist, neighbor.first, p[2] + 1});
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int n = 3;
  vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
  int src = 0, dst = 2, K = 1;
  cout << s.findCheapestPrice(n, flights, src, dst, K) << endl;  // 200
  K = 0;
  cout << s.findCheapestPrice(n, flights, src, dst, K) << endl;  // 500
  return 0;
}
