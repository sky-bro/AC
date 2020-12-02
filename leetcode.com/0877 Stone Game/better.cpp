#include <cstring>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> d(n, vector<int>(n));  // [j, j+i]
    for (int i = 0; i < n; ++i) d[0][i] = piles[i];
    vector<int> sums(n);
    sums[0] = piles[0];
    for (int i = 1; i < n; ++i) sums[i] = piles[i] + sums[i - 1];
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j + i < n; ++j) {
        d[i][j] = max(piles[j] - d[i - 1][j + 1] + sums[i + j] - sums[j],
                      piles[j + i] - d[i - 1][j] + sums[i + j - 1] -
                          (j ? sums[j - 1] : 0));
      }
    }
    return d[n - 1][0] > sums[n - 1] / 2;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> piles = {
      91, 66, 56, 43, 16, 41, 91, 12, 11,  29, 57, 34, 47, 57, 47, 98, 77,
      42, 23, 13, 55, 4,  76, 37, 87, 16,  57, 49, 15, 69, 54, 78, 94, 78,
      81, 59, 48, 4,  23, 66, 40, 85, 35,  92, 11, 81, 50, 78, 24, 61, 66,
      76, 33, 23, 1,  88, 99, 55, 17, 71,  72, 69, 60, 36, 87, 51, 36, 20,
      37, 17, 30, 19, 20, 60, 35, 60, 80,  6,  35, 99, 37, 93, 77, 32, 22,
      34, 55, 46, 18, 38, 86, 73, 75, 100, 80, 11, 46, 13, 40, 57};
  //   piles = {5, 3, 4, 5};
  // piles = {3, 2, 10, 4};
  Solution s;
  cout << s.stoneGame(piles) << endl;
  return 0;
}
