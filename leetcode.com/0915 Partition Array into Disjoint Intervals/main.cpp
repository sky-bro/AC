#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int partitionDisjoint(vector<int>& A) {
    multiset<int> st(A.begin(), A.end());
    int i = 0, n = A.size(), mx = 0;
    for (; i < n; ++i) {
      mx = max(mx, A[i]);
      st.erase(st.find(A[i]));
      if (mx <= *st.begin()) break;
    }
    return i + 1;
  }
};
