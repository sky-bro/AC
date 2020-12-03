#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int j = upper_bound(people.begin(), people.end(), limit / 2) -
            people.begin(),
        i = j - 1, n = people.size();
    int res = 0;
    int ii = 0;
    for (; i >= 0 && j < n;) {
      if (people[i] + people[j] <= limit) {
        ++res;
        ++j;
        --i;
      } else {
        --i;
        ++ii;
      }
    }
    return (i + 2 + ii) / 2 + res + (n - j);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> people = {1, 2};
  people = {3, 2, 2, 1};
  int limit = 3;
  people = {3, 5, 3, 4};
  limit = 5;
  people = {3, 1, 7};
  limit = 7;
  Solution s;
  cout << s.numRescueBoats(people, limit) << endl;
  return 0;
}
