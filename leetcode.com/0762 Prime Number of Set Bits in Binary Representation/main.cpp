#include <iostream>
#include <vector>

using namespace std;

// static vector<bool> a = [](){
//   vector<bool> res(33, true);
//   for (int i = 2; i < 33; ++i) {

//   }
  
// }();

class Solution {
private:
  bool chk(int num) {
    num = __builtin_popcount(num);
    if (num <= 1) return false;
    for (int i = 2; i < num; ++i) {
      if (num % i == 0) return false;
    }
    return true;
  }
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        while (L <= R) {
          if (chk(L)) ++res;
          ++L;
        }
        return res;
    }
};
