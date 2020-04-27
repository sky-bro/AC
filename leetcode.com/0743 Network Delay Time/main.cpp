#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
  int id;
  int dis;
  Node(int _id, int _dis): id(_id), dis(_dis) {}
  bool operator < (const Node& b) const {
    return dis > b.dis;
  }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      unordered_map<int, unordered_map<int, int>> G;
      for (auto &vi: times) G[vi[0]][vi[1]] = vi[2];
      priority_queue<Node> pq;
      pq.emplace(K, 0);
      int res = 0, cnt = N;
      vector<bool> vis(N+1);
      while (!pq.empty()) {
        Node node = pq.top(); pq.pop();
        if (vis[node.id]) continue;
        vis[node.id] = true;
        --cnt;
        res = node.dis;
        for (auto &p: G[node.id]) if (!vis[p.first]) {
          pq.emplace(p.first, node.dis + p.second);
        }
      }
      return cnt ? -1 : res;
    }
};
