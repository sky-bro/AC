#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int n = A.size();
    sort(A.begin(), A.end());
    vector<pair<int, int>> b;
    unordered_multiset<int> st;
    for (int i = 0; i < n; ++i) {
      b.emplace_back(B[i], i);
      st.insert(A[i]);
    }
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    vector<int> res(n, -1);
    for (; i < n; ++i) {
      for (; j < n; ++j) {
        if (A[j] > b[i].first) {
          res[b[i].second] = A[j];
          st.erase(st.find(A[j]));
          ++j;
          break;
        }
      }
    }
    i = 0;
    for (auto it = st.begin(); it != st.end(); ++i) {
      if (res[i] < 0) {
        res[i] = *it;
        ++it;
      }
    }
    return res;
  }
};
