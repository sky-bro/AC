#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ref: [C++/Java/Python] Solution with Explanation
// https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/118725/C%2B%2BJavaPython-Solution-with-Explanation

class Solution {
 public:
  int bestRotation(vector<int>& A) {
    int n = A.size();
    vector<int> change(n);
    // we lose A[i] when K = (i - A[i] + 1 + n) % n;
    // spcial case: A[i] = 0, we'll get this point back when we lose it...
    for (int i = 0; i < n; ++i) change[(i - A[i] + 1 + n) % n] -= 1;
    // get 1 more point each time we rotate (index 0 becomes index n - 1),
    // accumulate these changes
    for (int i = 1; i < n; ++i) change[i] += change[i - 1] + 1;
    return distance(change.begin(), max_element(change.begin(), change.end()));
  }
};
