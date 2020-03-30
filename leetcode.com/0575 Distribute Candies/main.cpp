#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int distributeCandies(vector<int>& candies) {
    unordered_set<int> st(candies.begin(), candies.end());
    return min(st.size(), candies.size() / 2);
  }
};