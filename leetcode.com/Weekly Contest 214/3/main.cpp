#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;

class Solution {
 public:
  int maxProfit(vector<int>& inventory, int orders) {
    LL res = 0;
    priority_queue<pair<LL, LL>> pq;
    pq.push(make_pair(0LL, 0LL));
    for (LL num : inventory) {
      pq.push(make_pair(num, 1LL));
    }
    LL remain = orders;
    while (remain) {
      auto tmp = pq.top();
      pq.pop();
      auto tmp2 = pq.top();
      if (tmp.first == tmp2.first) {
        pq.pop();
        tmp2.second += tmp.second;
        pq.push(tmp2);
        continue;
      }
      LL cnt = (tmp.first - tmp2.first) * tmp.second;
      if (cnt >= remain) {
        cnt = remain / tmp.second;
        res = (res + (tmp.first - cnt + 1 + tmp.first) * cnt * tmp.second / 2) %
              MOD;
        res = (res + (remain % tmp.second) * (tmp.first - cnt)) % MOD;
        break;
      } else {
        res = (res + (tmp2.first + 1 + tmp.first) * cnt / 2) % MOD;
        pq.pop();
        tmp2.second += tmp.second;
        pq.push(tmp2);
      }
      remain -= cnt;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> arr = {497978859, 167261111, 483575207, 591815159};
  int orders = 836556809;
  arr = {2, 5};
  orders = 4;
  arr = {5, 5, 5};
  orders = 6;
  Solution s;
  cout << s.maxProfit(arr, orders) << endl;
  return 0;
}
