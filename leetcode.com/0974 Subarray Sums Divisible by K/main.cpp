#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    vector<int> v(K);
    v[0] = 1;
    int res = 0, n = A.size();
    int sum = 0;
    for (int a : A) {
      sum += a;
      sum = (sum % K + K) % K;
      res += v[sum]++;
    }
    return res;
  }
};
