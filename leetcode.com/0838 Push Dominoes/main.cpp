#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string pushDominoes(string dominoes) {
    string res = "";
    int n = dominoes.size();
    vector<pair<char, int>> v;
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == '.') continue;
      v.emplace_back(dominoes[i], i);
    }
    int n2 = v.size();
    int i = 0;
    for (int ii = 0; ii < n2; ++ii) {
      if (v[ii].first == 'L') {
        for (; i <= v[ii].second; ++i) res.push_back('L');
      } else {
        for (; i < v[ii].second; ++i) res.push_back('.');
        if (ii+1 == n2) {
          for (; i < v[ii].second; ++i) res.push_back('.');
          for (; i < n; ++i) res.push_back('R');
          return res;
        }
        if (v[ii + 1].first == 'L') {
          int len = v[ii + 1].second + 1 - v[ii].second;
          for (int r = i + len / 2; i < r; ++i) res.push_back('R');
          if (len & 1) {
            res.push_back('.');
            ++i;
          }
          for (; i <= v[ii + 1].second; ++i) res.push_back('L');
          ++ii;
        } else {
          for (; i < v[ii + 1].second; ++i) res.push_back('R');
        }
      }
    }
    for (; i < n; ++i) res.push_back('.');
    return res;
  }
};

int main(int argc, char const *argv[]) {
  string dominos;
  Solution s;
  while (cin >> dominos) {
    cout << s.pushDominoes(dominos) << endl;
  }
  return 0;
}
