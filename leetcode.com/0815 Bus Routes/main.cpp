#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// BFS

class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    if (S == T) return 0;
    int n = routes.size(), res = 0;
    queue<int> q;
    // bus visited
    unordered_set<int> vis;
    unordered_map<int, vector<int>> stop_buses;
    for (int i = 0; i < n; ++i) {
      for (int s : routes[i]) {
        stop_buses[s].push_back(i);
      }
    }

    q.push(S);
    while (!q.empty()) {
      ++res;
      for (int i = q.size(); i > 0; --i) {
        int cur_stop = q.front();
        q.pop();
        for (int bus : stop_buses[cur_stop]) {
          if (vis.find(bus) != vis.end()) continue;
          vis.insert(bus);
          for (int next_stop : routes[bus]) {
            if (next_stop == T) return res;
            q.push(next_stop);
          }
        }
      }
    }
    return -1;
  }
};
