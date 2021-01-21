#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll base = 27;
const int MOD = 1e9 + 7;

// rolling hash ?
// lowercase letters: 1-26
// base: 27
// mod: 1e9 + 7

// target: aabcaca
// stamp:  abca
//         a????ca 1
//         ?????ca 0
//         ??????? 3
class Solution {
 private:
  bool ok;
  int n1, n2;
  vector<int> res;
  vector<ll> hash_prefix, hash_suffix;
  // use rolling hash to find prefix or suffix
  void f(const string &s, string &t, int l, int r) {
    int len = r - l;
    //   bool found = false;
    // search for max suffix of s
    if (l != 0) {  // l->r
      int mx = 0;
      ll hash = 0;
      for (int cur = 0; cur < len && cur < n1; ++cur) {
        hash = (hash * base % MOD + t[l + cur] - 'a') % MOD;
        if (hash_suffix[cur] == hash) {
          mx = cur + 1;
        }
      }
      if (mx) {
        res.push_back(l - (n1 - mx));
        if (mx < len) {
          f(s, t, l + mx, r);
        }
        return;
      }
    }

    // search for max prefix of s
    if (r != n2) {  // from r->l
      int mx = 0;
      ll hash = 0;
      for (int cur = 0; cur < len && cur < n1; ++cur) {
        hash = (hash * base % MOD + t[r - 1 - cur] - 'a') % MOD;
        if (hash_prefix[cur] == hash) {
          mx = cur + 1;
        }
      }
      if (mx) {
        res.push_back(r - mx);
        if (mx < len) {
          f(s, t, l, r - mx);
        }
        return;
      }
    }

    int i = s.find(t.substr(l, len));
    if (i == -1 || l == 0 || r == n2)
      ok = false;
    else
      res.push_back(l - i);
  }

 public:
  vector<int> movesToStamp(string stamp, string target) {
    ok = true;
    res.clear();
    n1 = stamp.size(), n2 = target.size();
    hash_prefix.resize(n1), hash_suffix.resize(n1);
    for (ll hash_p = 0, hash_s = 0, b = 1, i = 0; i < n1;
         b = (b * base) % MOD, ++i) {
      hash_prefix[i] = hash_p = (hash_p + b * (stamp[i] - 'a') % MOD) % MOD;
      hash_suffix[i] = hash_s =
          (hash_s + b * (stamp[n1 - 1 - i] - 'a') % MOD) % MOD;
    }
    // use kmp find all stamps first
    // or not, just use string.find
    int l = -n1;
    while (ok) {
      int i = target.find(stamp, max(l + 1, 0));
      if (i != -1) {
        res.push_back(i);
        if (l + n1 < i) {
          f(stamp, target, l + n1, i);
        }
      } else {  // no more stamp found, break
        if (l < 0) {
          return {};
        } else if (l + n1 != n2) {
          f(stamp, target, l + n1, n2);
        }
        break;
      }
      l = i;
    }
    if (!ok) return {};
    reverse(res.begin(), res.end());
    return res;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Solution s;
  string target = "aabcaca", stamp = "abca";                        // {3, 0, 1}
  target = "mdadddaaaa", stamp = "mda";                             // {}
  target = "bebedabebbedaefaeddccbced", stamp = "bedaefaeddccbce";  // {}
  printArr(s.movesToStamp(stamp, target));
  return 0;
}
