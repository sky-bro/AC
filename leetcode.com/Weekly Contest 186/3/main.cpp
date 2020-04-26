#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        vector<pair<int, int>> pos;
        for (int i = nums.size() - 1; i >= 0; --i) {
          for (int j = nums[i].size() - 1; j >= 0; --j) {
            pos.emplace_back(i, j);
          }
        }
        sort(pos.begin(), pos.end(), [](const pair<int,int>&a, const pair<int,int>&b){
          if (a.first + a.second == b.first + b.second) return a.first > b.first;
          else return a.first + a.second < b.first + b.second;
        });
        for (auto &p: pos) {
          res.push_back(nums[p.first][p.second]);
        }
        return res;
    }
};
