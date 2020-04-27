#include <iostream>
#include <vector>

using namespace std;
// ref: [C++] Clean code with explanation: O(n) time and O(1) space (beats 99.13%)
// https://leetcode.com/problems/daily-temperatures/discuss/121787/C%2B%2B-Clean-code-with-explanation%3A-O(n)-time-and-O(1)-space-(beats-99.13)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        for (int i = n-2; i >= 0; --i) {
          int j = i + 1;
          while (T[j] <= T[i]) {
            if (res[j] == 0) {j = n; break;}
            else j = res[j] + j;
          }
          res[i] = j == n ? 0 : j - i;
        }
        return res;
    }
};
