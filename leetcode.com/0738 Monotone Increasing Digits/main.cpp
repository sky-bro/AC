#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int monotoneIncreasingDigits(int N) {
    vector<int> num;
    int N0 = N;
    while (N) {
      num.push_back(N % 10);
      N /= 10;
    }
    int n = num.size(), i = n - 2;
    while (i >= 0 && num[i] >= num[i + 1]) --i;
    if (i < 0) return N0;

    while (true) {
      --num[i + 1];
      int j = i + 1;
      for (; j < n - 1 && num[j] >= num[j + 1]; ++j)
        ;
      if (j == n - 1) {
        for (; i >= 0; --i) {
          num[i] = 9;
        }
        break;
      } else
        i = j;
    }
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
      res = res * 10 + num[i];
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int N;
  while (cin >> N) {
    cout << s.monotoneIncreasingDigits(N) << endl;
  }
  return 0;
}
