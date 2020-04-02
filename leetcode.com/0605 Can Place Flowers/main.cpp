#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n < 1) return true;
    int N = flowerbed.size();
    flowerbed.push_back(0);
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
      --n;
    }
    for (int i = 2; i < N && n; ++i) {
      if (flowerbed[i]) {
        ++i;
      } else if (!flowerbed[i - 1] && !flowerbed[i + 1]){
        --n;
        ++i;
      }
    }
    return n == 0;
  }
};