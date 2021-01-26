#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end());
    for (int i = A.size() - 1; i >= 2; --i) {
      if (A[i] < A[i - 1] + A[i - 2]) return A[i - 1] + A[i - 2] + A[i];
    }
    return 0;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {2, 1, 2};
  cout << s.largestPerimeter(A) << endl;
  return 0;
}
