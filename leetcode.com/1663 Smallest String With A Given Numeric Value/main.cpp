#include <iostream>
#include <vector>

using namespace std;

char arr[100100];
class Solution {
 public:
  string getSmallestString(int n, int k) {
    int i = 0;
    while (i != n) {
      if ((k + 25) / 26 == n - i) {
        arr[i++] = ('a' - 1 + (k % 26 ? k % 26 : 26));
        k -= arr[i - 1] - 'a' + 1;
      } else {
        arr[i++] = ('a');
        --k;
      }
    }
    arr[i] = 0;
    return string(arr);
  }
};
