#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int kSimilarity(string A, string B) {
    if (A == B) return 0;
    int n = A.size();
    vector<char> a, b;
    for (int i = 0; i < n; ++i) {
      if (A[i] != B[i]) {
        a.push_back(A[i]);
        b.push_back(B[i]);
      }
    }
    n = a.size();
    int d = 0;
    queue<vector<char>> q;
    q.push(a);
    while (!q.empty()) {
      for (int sz = q.size(); sz; --sz) {
        auto v = q.front();
        q.pop();
        int i = 0;
        while (i < n && v[i] == b[i]) ++i;
        if (i == n) return d;
        for (int j = i + 1; j < n; ++j) {
          if (v[j] == b[i] && v[j] != b[j]) {
            auto nv = v;
            swap(nv[i], nv[j]);
            q.push(nv);
          }
        }
      }
      ++d;
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string a = "ab";
  string b = "ba";
  while (cin >> a >> b) cout << s.kSimilarity(a, b) << endl;
  return 0;
}
