#include <bits/stdc++.h>
using namespace std;

int __fastio = []() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin.tie(nullptr);
  return 0;
}();

int ids[30];

int F(int x) { return x == ids[x] ? x : (ids[x] = F(ids[x])); }

void U(int a, int b) {
  int id1 = F(a), id2 = F(b);
  ids[id2] = id1;
}

class Solution {
 public:
  bool equationsPossible(vector<string> &equations) {
    iota(ids, ids + 26, 0);
    for (string &s : equations) {
      if (s[1] == '=') {
        U(s[0] - 'a', s[3] - 'a');
      }
    }

    for (string &s : equations) {
      if (s[1] == '!') {
        if (F(s[0] - 'a') == F(s[3] - 'a')) return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> equations = {"a==b"};
  cout << s.equationsPossible(equations) << endl;
  return 0;
}

