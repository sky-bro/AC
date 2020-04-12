// ref: hadlock?
// http://users.eecs.northwestern.edu/~haizhou/357/lec6.pdf
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

struct Node {
  int r, c, d;
  bool operator<(const Node& n) const { return (d < n.d); }
};

int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

Node* dq = new Node[3000];
Node *dqf, *dqb;
vector<Node> v;
char mask[2500];

// 20ms, my original bfs solution took 1700ms+
class Solution {
 public:
  int cutOffTree(vector<vector<int>>& forest) {
    R = forest.size();
    C = forest[0].size();
    v.clear();
    for (int i = 0; i < forest.size(); i++) {
      for (int j = 0; j < forest[i].size(); j++) {
        if (forest[i][j] > 1) {
          Node n = {i, j, forest[i][j]};
          v.push_back(n);
        }
      }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    Node cur = {0, 0, 1};
    for (int i = 0; i < v.size(); i++) {
      int step = hadlock(forest, cur.r, cur.c, v[i].r, v[i].c);
      if (step < 0) {
        return -1;
      }

      ans += step;
      cur = v[i];
    }
    return ans;
  }

 private:
  int R, C;
  int hadlock(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {
    dqf = dqb = dq + 500; // deque, get next node from dqf (closer nodes put from dqf)
    Node cur = {sr, sc, 0}; // 0 is detour count
    *dqb = cur;
    ++dqb;
    memset(mask, 0, R * C); // all unvisited
    
    while (dqf != dqb) { // while deque is not empty
      Node n = *dqf;
      ++dqf;
      if (mask[n.r * C + n.c]) { // check if current node is visited
        continue;
      }
      mask[n.r * C + n.c] = true; // is visited now
      if (n.r == tr && n.c == tc) {
        return abs(sr - tr) + abs(sc - tc) + 2 * n.d;
      }
      for (int i = 0; i < 4; i++) {
        int nr = n.r + direct[i][0];
        int nc = n.c + direct[i][1];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && forest[nr][nc] > 0) {
          bool closer =
              abs(n.r - tr) > abs(nr - tr) || abs(n.c - tc) > abs(nc - tc);
          if (closer) {
            // closer nodes put from dqf
            *(--dqf) = {nr, nc, n.d};
          } else {
            // further nodes put from dqb
            *(dqb++) = {nr, nc, n.d + 1};
          }
        }
      }
    }

    return -1;
  }
};