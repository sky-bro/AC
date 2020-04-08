#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(
        pairs.begin(), pairs.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    int pre = pairs[0][1], res = 1;
    for (auto& pair : pairs) {
      if (pair[0] > pre) {
        pre = pair[1];
        ++res;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> pairs = {{-10, -8}, {8, 9}, {-5, 0}, {6, 10},
                               {-6, -4},  {1, 7}, {9, 10}, {-4, 7}};
  cout << s.findLongestChain(pairs) << endl;
  return 0;
}
