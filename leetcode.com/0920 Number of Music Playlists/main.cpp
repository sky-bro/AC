#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
 public:
  int numMusicPlaylists(int N, int L, int K) {
    // Every song is played at least once
    // A song can only be played again only if K other songs have been played
    // window K (songs must be different)
    // i different songs played till j-th song
    // d[i][j] = d[i-1][j-1] * (N - min(K, j-1)) + d[i] * max(i - K, 0) -- new
    // song, old song at j-th
    vector<vector<ll>> d(N + 1, vector<ll>(L + 1));
    d[1][1] = N;
    if (K == 0)
      for (int i = 2; i <= L; ++i) d[1][i] = N;
    for (int i = 2; i <= N; ++i) {
      for (int j = i; j <= L; ++j) {
        d[i][j] = (d[i - 1][j - 1] * (N - max(i - 1, 0)) % MOD +
                   d[i][j - 1] * max(i - K, 0) % MOD) %
                  MOD;
      }
    }
    return d[N][L];
  }
};

int main(int argc, char const *argv[]) {
  int N, L, K;
  Solution s;
  while (cin >> N >> L >> K) {
    cout << s.numMusicPlaylists(N, L, K) << endl;
  }
  return 0;
}
