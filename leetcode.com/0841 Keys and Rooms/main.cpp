#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> vis(n);
    vis[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int key = q.front();
      q.pop();
      for (int next_room : rooms[key]) {
        if (vis[next_room]) continue;
        vis[next_room] = true;
        q.push(next_room);
      }
    }
    return all_of(vis.begin(), vis.end(), [](bool t) { return t; });
  }
};
