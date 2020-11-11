#include <iostream>

using namespace std;

typedef long long LL;

const int MOD = 1e9;

pair<LL, LL> f(char *cmd, int &i) {
  LL dx = 0, dy = 0;
  while (cmd[i]) {
    switch (cmd[i]) {
      case 'N':
        --dy;
        dy %= MOD;
        ++i;
        break;
      case 'S':
        ++dy;
        dy %= MOD;
        ++i;
        break;
      case 'E':
        ++dx;
        dx %= MOD;
        ++i;
        break;
      case 'W':
        --dx;
        dx %= MOD;
        ++i;
        break;

      case ')':
        ++i;
        return make_pair(dx, dy);
        break;

      default:  // digits
        int t = (cmd[i] - '0');
        i += 2;
        auto p = f(cmd, i);
        dx = (dx + t * p.first) % MOD;
        dy = (dy + t * p.second) % MOD;
        break;
    }
  }
  return make_pair(dx, dy);
}

char cmd[2001];
void solve(int case_num) {
  scanf("%s", cmd);
  int i = 0;
  auto p = f(cmd, i);
  int res = 0;
  p.first = (1LL + p.first + MOD) % MOD;
  p.second =  (1LL + p.second + MOD) % MOD;
  if (p.first == 0) p.first = MOD;
  if (p.second == 0) p.second = MOD;
  printf("Case #%d: %lld %lld\n", case_num,p.first, p.second);
}

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  return 0;
}
