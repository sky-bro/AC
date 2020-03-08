#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    int res = 0, max_num = 0, n = light.size();
    for (int i = 0; i < n; ++i) {
      max_num = max(max_num, light[i]);
      if (i + 1 == max_num) ++res;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> light = {4, 1, 2, 3};
  cout << s.numTimesAllBlue(light) << endl;
  return 0;
}
