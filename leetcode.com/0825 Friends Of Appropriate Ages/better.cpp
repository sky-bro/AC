#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numFriendRequests(vector<int>& ages) {
    vector<int> bucket(121);
    for (int age : ages) bucket[age]++;
    for (int i = 1; i <= 120; ++i) bucket[i] += bucket[i - 1];
    int res = 0;
    for (int i = 1; i <= 120; ++i) {
      if (bucket[i] - bucket[i - 1]) {
        int l_age = i / 2 + 7;
        if (l_age < i) {
          res += (bucket[i] - bucket[i - 1]) * (bucket[i] - bucket[l_age] - 1);
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> ages = {16, 16};
  ages = {108, 115, 5, 24, 82};  // 3
  cout << s.numFriendRequests(ages) << endl;
  return 0;
}
