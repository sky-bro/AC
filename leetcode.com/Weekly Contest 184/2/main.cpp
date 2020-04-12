#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
      int n =queries.size();
        vector<int> res;
        vector<int> nums(m+1);
        iota(nums.begin(), nums.end(), -1);
        for (int query: queries) {
          res.push_back(nums[query]);
          int bak = res.back(), cnt = bak;
          for (int i = 1; i <= m && cnt; ++i) {
            if (nums[i] < bak) {
              --cnt;
              ++nums[i];
            }
          }
          nums[query] = 0;
        }
        return res;
    }
};