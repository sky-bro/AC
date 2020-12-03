#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

class Solution {
 public:
  string decodeAtIndex(string S, int K) {
    if (K == 1) return string(1, S[0]);
    ull N = 0;
    int i = 0;
    while (true) {
      if (S[i] <= '9' && S[i] >= '2') {
        N *= S[i] - '0';
      } else {
        ++N;
      }
      if (N >= K) break;
      ++i;
    }
    --K;
    while (true) {
      // if (N == K) return string(1, S[i]);
      if (S[i] <= '9' && S[i] >= '2') {
        N /= S[i] - '0';
        K %= N;
      } else {
        if (K == --N) return string(1, S[i]);
      }
      if (K == 0) return string(1, S[0]);
      --i;
    }
    return "sky";
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string S;
  int K;
  while (cin >> S >> K) {
    cout << s.decodeAtIndex(S, K) << endl;
  }
  return 0;
}
