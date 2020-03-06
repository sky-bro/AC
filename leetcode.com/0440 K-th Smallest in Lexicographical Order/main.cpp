#include <iostream>
#include <vector>

using namespace std;

// TLE: O(k) naive
class Solution0 {
 public:
  int findKthNumber(int n, int k) {
    int res = 1;
    for (int i = 0; i < k; ++i) {
      if (res <= n / 10) {  // may overflow: res * 10 <= n
        res *= 10;
      } else {
        if (res == n) res /= 10;
        ++res;
        while (res % 10 == 0) res /= 10;
      }
    }
    return res;
  }
};

// ref:
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/discuss/92254/C%2B%2BPython-0ms-O((log-n)2)-time-O(1)-space-super-easy-solution-with-detailed-explanations
class Solution {
 public:
  int findKthNumber(int n, int k) {
    int result = 1;
    for (--k; k > 0;) {
      // calculate #|{result, result*, result**, result***, ...}|
      int count = 0;
      for (long long first = static_cast<long long>(result), last = first + 1;
           first <= n;               // the interval is not empty
           first *= 10, last *= 10)  // increase a digit
      {
        // valid interval = [first, last) union [first, n]
        count += static_cast<int>(
            (min(n + 1LL, last) - first));  // add the length of interval
      }

      if (k >= count) {  // skip {result, result*, result**, result***, ...}
        // increase the current prefix
        ++result;
        k -= count;
      } else {  // not able to skip all of {result, result*, result**,
                // result***, ...}
        // search more detailedly
        result *= 10;
        --k;
      }
    }
    return result;
  }
};