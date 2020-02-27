#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int val, i, j;
  bool operator<(const Node& b) const { return val > b.val; }
  Node(int _val, int _i, int _j) : val(_val), i(_i), j(_j) {}
};

class Solution {
 private:
  int m, n, res, max_allow_height, remain_cnt;
  void visit(int i, int j, vector<vector<bool>>& visited,
             priority_queue<Node>& pq, vector<vector<int>>& heightMap) {
    if (visited[i + 1][j + 1]) return;
    int val = heightMap[i][j];
    visited[i + 1][j + 1] = true;
    --remain_cnt;
    pq.emplace(val, i, j);
    if (max_allow_height > val) {
      res += max_allow_height - val;
    }
  }

 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    // initialization
    m = heightMap.size();
    if (m < 3) return 0;
    n = heightMap[0].size();
    if (n < 3) return 0;
    res = 0;
    vector<vector<bool>> visited(m + 2, vector<bool>(n + 2));
    priority_queue<Node> pq;
    for (int i = 0; i < n; ++i) {
      visited[0][i + 1] = visited[m + 1][i + 1] = visited[1][i + 1] =
          visited[m][i + 1] = true;
      pq.emplace(heightMap[0][i], 0, i);
      pq.emplace(heightMap[m - 1][i], m - 1, i);
    }
    for (int i = 1; i < m - 1; ++i) {
      visited[i + 1][0] = visited[i + 1][n + 1] = visited[i + 1][1] =
          visited[i + 1][n] = true;
      pq.emplace(heightMap[i][0], i, 0);
      pq.emplace(heightMap[i][n - 1], i, n - 1);
    }
    visited[1][0] = visited[1][n + 1] = visited[m][0] = visited[m][n + 1] =
        true;

    // work
    remain_cnt = m * n - 2 * (m + n - 2);
    max_allow_height = INT32_MIN;
    while (remain_cnt) {
      Node node = pq.top();
      pq.pop();
      max_allow_height = max(node.val, max_allow_height);
      // up
      visit(node.i - 1, node.j, visited, pq, heightMap);
      // down
      visit(node.i + 1, node.j, visited, pq, heightMap);
      // left
      visit(node.i, node.j - 1, visited, pq, heightMap);
      // right
      visit(node.i, node.j + 1, visited, pq, heightMap);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> heightMap = {
      {1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
  cout << s.trapRainWater(heightMap) << endl;  // 4
  heightMap = {{12, 13, 1, 12},
               {13, 4, 13, 12},
               {13, 8, 10, 12},
               {12, 13, 12, 12},
               {13, 13, 13, 13}};  // 14
  cout << s.trapRainWater(heightMap) << endl;
  return 0;
}
