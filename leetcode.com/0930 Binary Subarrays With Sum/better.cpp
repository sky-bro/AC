#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    unordered_map<int, int> c({{0, 1}});
    int psum = 0, res = 0;
    for (int i : A) {
      psum += i;
      res += c[psum - S];
      c[psum]++;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {0, 0, 0, 0, 0};
  int S = 0;
  cout << s.numSubarraysWithSum(A, S) << endl;
  return 0;
}
