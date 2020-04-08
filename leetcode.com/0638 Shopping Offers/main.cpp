// ref: Concise c++ DFS solution, 6ms
// https://leetcode.com/problems/shopping-offers/discuss/105252/Concise-c%2B%2B-DFS-solution-6ms
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int operator*(const vector<int>& a, const vector<int>& b) {
  return inner_product(a.begin(), a.end(), b.begin(), 0);
}

bool operator>(const vector<int>&a, const vector<int>&b) {
  for (int i = a.size()-2; i >= 0; --i ) {
    if (a[i] > b[i]) return true;
  }
  return false;
}

void operator-=(vector<int>&a, const vector<int>&b) {
  for (int i = a.size()-1;i >=0; --i) {
    a[i] -= b[i];
  }
}

void operator+=(vector<int>&a, const vector<int>&b) {
  for (int i = a.size()-1;i >=0; --i) {
    a[i] += b[i];
  }
}

class Solution {
 public:
  int shoppingOffers(vector<int>& price, vector<vector<int>>& special,
                     vector<int>& needs) {
    int c = needs * price;
    for (auto &vi: special) {
      if (vi.back() > c || vi > needs) continue;
      needs -= vi;
      c = min(c, vi.back() + shoppingOffers(price, special, needs));
      needs += vi;
    }
    return c;
  }
};