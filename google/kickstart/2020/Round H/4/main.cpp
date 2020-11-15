#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;
typedef unsigned long ul;

int N, Q;

bool G[26][26];

void query(int a, int b, vector<unordered_set<int>> &names) {
  queue<int> q;
  int dep = 1;
  vector<bool> vis(26);
  for (int c : names[a]) {
    q.push(c);
    vis[c] = true;
  }
  while (!q.empty()) {
    ++dep;
    for (int sz = q.size(); sz; --sz) {
      int c = q.front();
      q.pop();
      if (names[b].count(c)) {
        cout << dep << " ";
        return;
      }
      for (int i = 0; i < 26; ++i) {
        if (G[c][i] && !vis[i]) {
          q.push(i);
          vis[i] = true;
        }
      }
    }
  }
  cout << "-1 ";
}

void solve(int case_num) {
  cin >> N >> Q;
  memset(G, 0, sizeof(G));
  vector<unordered_set<int>> names(N);
  string s;
  for (int i = 0; i < N; ++i) {
    cin >> s;
    for (char c : s) names[i].insert(c - 'A');
    for (int c : names[i]) {
      for (int cc : names[i]) {
        G[c][cc] = 1;
      }
    }
  }

  for (int i = 0; i < Q; ++i) {
    int a, b;
    cin >> a >> b;
    query(--a, --b, names);
  }
  cout << "\n";
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve(t);
  }
  return 0;
}
