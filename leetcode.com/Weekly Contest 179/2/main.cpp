#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    set<int> s;
    int res = 0;
    for (int num : light) {
      s.insert(num);
      if (s.size() == *(--s.end())) ++res;
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
