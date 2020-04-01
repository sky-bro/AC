#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  inline bool is90(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
    if ((p2[0] == p1[0] && p2[1] == p1[1]) || p3[0] == p1[0] && p3[1] == p1[1])
      return false;
    return (p2[0] - p1[0]) * (p3[0] - p1[0]) +
               (p2[1] - p1[1]) * (p3[1] - p1[1]) ==
           0;
  }
  inline bool eqlen(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
    int a1 = p2[0] - p1[0], b1 = p2[1] - p1[1];
    int a2 = p3[0] - p1[0], b2 = p3[1] - p1[1];
    return (a1 * a1 + b1 * b1) == (a2 * a2 + b2 * b2);
  }

 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                   vector<int>& p4) {
    if (is90(p1, p2, p3)) {
      return eqlen(p1, p2, p3) && is90(p2, p1, p4) && is90(p3, p1, p4);
    } else if (is90(p1, p2, p4)) {
      return eqlen(p1, p2, p4) && is90(p2, p1, p3) && is90(p4, p1, p3);
    } else if (is90(p1, p3, p4)) {
      return eqlen(p1, p3, p4) && is90(p3, p1, p2) && is90(p4, p1, p2);
    }
    return false;
  }
};