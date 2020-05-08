#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// ref: from fastest solution
class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {
    int swaps = 0;
    for (int i = 0; i < row.size(); i += 2) {
      int a = row[i];
      int b = row[i + 1];

      if ((a % 2 == 0) && (b == a + 1)) {
        // couple already next to each other
        continue;
      } else if ((a % 2 == 1) && (b == a - 1)) {
        // couple already next to each other
        continue;
      } else {
        // couple not next to each other, find and swap
        swaps++;
        int find = (a % 2 == 0) ? a + 1 : a - 1;
        for (int j = i + 2; j < row.size(); j++) {
          if (find == row[j]) {
            row[i + 1] = find;
            row[j] = b;
            break;
          }
        }
      }
    }

    return swaps;
  }
};