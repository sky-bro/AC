#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int>& operator+(vector<int>& a, const vector<int>& b) {
  a[0] += b[0];
  a[1] += b[1];
  return a;
}
vector<int>& operator-(vector<int>& a, const vector<int>& b) {
  a[0] -= b[0];
  a[1] -= b[1];
  return a;
}
int operator*(const vector<int>& a, const vector<int>& b) {
  return a[0] * b[0] + a[1] * b[1];
}

class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    set<vector<int>> obs(obstacles.begin(), obstacles.end());
    int res = 0;
    vector<int> d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int k = 0;
    vector<int> cur = {0, 0};
    for (int cmd : commands) {
      if (cmd == -1) {
        k = (k + 1) % 4;
      } else if (cmd == -2) {
        k = (k + 3) % 4;
      } else {
        for (; cmd && obs.find(cur + d[k]) == obs.end(); --cmd)
          ;
        if (cmd) cur - d[k];
      }
      res = max(res, cur * cur);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> cmds = {-2, 8, 3, 7, -1};
  vector<vector<int>> obs = {{-4, -1}, {1, -1}, {1, 4}, {5, 0},   {4, 5},
                             {-2, -1}, {2, -5}, {5, 1}, {-3, -1}, {5, -3}};
  obs = {{-3, 0}};
  cout << s.robotSim(cmds, obs) << endl;
  return 0;
}
