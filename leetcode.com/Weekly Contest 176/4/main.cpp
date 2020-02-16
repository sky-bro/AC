#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>

using namespace std;

// ref:
// https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/510214/C%2B%2B-Reaching-Points-Work-Backwards
class Solution {
 public:
  bool isPossible(vector<int>& target) {
    int N = target.size();
    long long S = 0;
    for (int x : target) S += x;
    priority_queue<int> pq(target.begin(), target.end());
    while (S != N) {
      long long num = pq.top(), x = 2 * num - S;
      pq.pop();
      if (x < 1) return false;
      pq.push(x);
      S -= num - x;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> target{8, 5};
  cout << s.isPossible(target) << endl;
  return 0;
}
