#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> mp(m+n, -1);
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            if (~mp[j-i+m]) {
              if (mp[j-i+m] != matrix[i][j]) return false;
            } else {
              mp[j-i+m] = matrix[i][j];
            }
          }
        }
        return true;
    }
};
