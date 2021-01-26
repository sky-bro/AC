#include <iostream>
#include <vector>

using namespace std;

// ref: c++, recursive, easy to understand
// https://leetcode.com/problems/least-operators-to-express-number/discuss/208445/c%2B%2B-recursive-easy-to-understand
class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) {
    // At this time, you can get target either by add target times x/x or
    // subtract (x - target) times x/x to x For example, x = 3, target = 2.
    // Then, 3/3 + 3/3 or 3 - 3/3 is possible result
    if (x > target) {
      return min(target * 2 - 1, (x - target) * 2);
    }
    if (x == target) {  // just push x at the end
      return 0;
    }

    long long sums = x;
    int times = 0;
    while (sums < target) {  // this is gready, put as much as possible 'x'
      times++;
      sums *= x;
    }

    if (sums == target) {  // one more 'x' you put, one more operator
      return times;
    }

    // when you have remainder, you have two choices, one is add, the other is
    // subtract for example, x = 3, target = 5. Then, 5 = 3 + 2 or 5 = 9 - 4
    int l = INT32_MAX, r = INT32_MAX;
    if (sums - target < target) {
      l = leastOpsExpressTarget(x, sums - target) + times;  // using subtract
    }
    r = leastOpsExpressTarget(x, target - (sums / x)) + times - 1;  // using add
    return min(l, r) + 1;  // No matter +/- used, one more operator is add
  }
};
