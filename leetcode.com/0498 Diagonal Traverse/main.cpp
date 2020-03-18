#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) return {};
    int n = matrix[0].size();
    if (n == 0) return {};
    vector<int> res;
    bool down = false;
    for (int i = 0, j = 0;; down = !down) {
      if (down) {
        while (true) {
          res.push_back(matrix[i][j]);
          if (i + 1 < m && j - 1 >= 0) {
            ++i;
            --j;
          } else {
            break;
          }
        }
        if (i + 1 < m) {
          ++i;
        } else if (j + 1 < n) {
          ++j;
        } else {
          break;
        }
      } else {
        while (true) {
          res.push_back(matrix[i][j]);
          if (i - 1 >= 0 && j + 1 < n) {
            --i;
            ++j;
          } else {
            break;
          }
        }
        if (j + 1 < n) {
          ++j;
        } else if (i + 1 < m) {
          ++i;
        } else {
          break;
        }
      }
    }
    return res;
  }
};