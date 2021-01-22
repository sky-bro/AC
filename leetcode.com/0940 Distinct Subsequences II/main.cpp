#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

/*
aba
[0,1,3,3+3+1-1]
aaa
[0,1,1+1+1-1,2+2+1-1-1]
dacaba
[0,1,3,7,7+7+1-2,27,55-8]
dacabab
[0,1,3,7,7+7+1-2,27,55-8,95-14]
dacababa
[0,1,3,7,7+7+1-2,27,55-8,95-14,163-28]
*/

ll dup[26];
// dp
class Solution {
 private:
  int n;

 public:
  int distinctSubseqII(string S) {
    n = S.size();
    memset(dup, 0, sizeof(dup));
    int res;
    for (ll i = 1, pre = 0; i <= n; ++i, pre = res) {
      res = (pre * 2 % MOD + 1 - dup[S[i - 1] - 'a'] + MOD) % MOD;
      dup[S[i - 1] - 'a'] = (pre + 1) % MOD;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string S =
      "zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcni"
      "lcjjlpoeoqqoqpswtqdpvszfaksn";
  cout << s.distinctSubseqII(S) << endl;

  return 0;
}
