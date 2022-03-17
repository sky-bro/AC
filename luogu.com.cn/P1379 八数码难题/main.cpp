#include <bits/stdc++.h>

#include <queue>
using namespace std;
// clang-format off
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(0); return 0; } ();
#ifdef LOCAL_DEBUG
#include <competitive.h>
#else
#define pp(...)
#define ppp(...)
#endif
// clang-format on

// 上下左(移动前不能是3倍数)右(移动后不能是3倍数)
int d4[] = {-3, +3, -1, 1};
struct node {
  string state;
  int g;  // f = g + h
  int h;
  bool operator<(const node &other) const { return g + h > other.g + h; }
  node(const string &state, int g, int h) : state(state), g(g), h(h) {}
};
// A*: 一种特殊的Best First Search, 只不过每个节点的代价非真实值, 而是:
// 当前移动步数 + 预期剩余步数
// 当预期剩余步数 <= 真实剩余步数时(也是A*的要求), 采用BFS能够得到最优代价
// 预期剩余步数: 跟目标相比不同的块数(且不包括0?)
void solve() {
  string s, t = "123804765";
  set<string> vis;
  int n = t.size();
  cin >> s;
  int h = 0;  // 预期剩余步数
  // 这里按照A*算法要求, 需要这样去除0, 但实际上不去除也是正确的?
  for (int i = 0; i < n; ++i) h += s[i] != t[i] && s[i] != '0';
  priority_queue<node> q;
  q.emplace(s, 0, h);
  vis.insert(s);
  while (!q.empty()) {
    int i = 0;
    node cur = q.top();
    q.pop();
    if (cur.h == 0) {
      cout << cur.g << "\n";
      break;
    }
    ++cur.g;
    while (cur.state[i] != '0') ++i;
    for (int j = 0; j < 4; ++j) {
      int ni = i + d4[j];
      if (ni >= 0 && ni <= 8 && !(j == 2 && i % 3 == 0) &&
          !(j == 3 && ni % 3 == 0)) {
        int old_diff = (cur.state[ni] != t[ni]);
        swap(cur.state[i], cur.state[ni]);
        int new_diff = (cur.state[i] != t[i]);
        if (!vis.count(cur.state)) {
          vis.insert(cur.state);
          cur.h += new_diff - old_diff;
          q.push(cur);
          cur.h -= new_diff - old_diff;
        }
        swap(cur.state[i], cur.state[ni]);
      }
    }
  }
}

int main() {
#ifdef LOCAL_DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T0;
  cin >> T0;
  for (int t0 = 1; t0 <= T0; ++t0) {
    cout << "--------" << t0 << "--------\n";
#endif
    int T = 1;
    while (T--) {
      solve();
    }
#ifdef LOCAL_DEBUG
  }
#endif
  return 0;
}
