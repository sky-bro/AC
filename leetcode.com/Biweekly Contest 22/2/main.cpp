#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, unordered_set<int>> m;
    for (auto& reservedSeat : reservedSeats) {
      m[reservedSeat[0]].insert(reservedSeat[1]);
    }
    int res = 2 * (n - m.size());
    for (auto it = m.begin(); it != m.end(); ++it) {
      int d = 0;
      if (!it->second.count(2) && !it->second.count(3) &&
          !it->second.count(4) && !it->second.count(5))
        ++d;
      if (!it->second.count(6) && !it->second.count(7) &&
          !it->second.count(8) && !it->second.count(9))
        ++d;
      if (d)
        res += d;
      else if (!it->second.count(6) && !it->second.count(7) &&
               !it->second.count(4) && !it->second.count(5))
        ++res;
    }
    return res;
  }
};