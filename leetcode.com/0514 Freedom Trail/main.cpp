#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    vector<int> m[26];
    int len_r = ring.length(), len_k = key.length();
    for (int i = 0; i < len_r; ++i) m[ring[i] - 'a'].push_back(i);
    vector<pair<int, int>> *cur = new vector<pair<int, int>>();
    cur->emplace_back(0, 0);  // steps, idx

    for (int i = 0; i < len_k; ++i) {
      vector<pair<int, int>> *tmp = new vector<pair<int, int>>();
      for (int idx : m[key[i] - 'a']) tmp->emplace_back(INT32_MAX, idx);

#define DIS(a, b) \
  (a < b ? min(b - a, len_r + a - b) : min(a - b, len_r + b - a))

      for (auto itc = cur->begin(); itc != cur->end(); ++itc) {
        for (auto itt = tmp->begin(); itt != tmp->end(); ++itt) {
          int dis = DIS(itt->second, itc->second) + 1;
          if (itt->first > dis + itc->first) itt->first = dis + itc->first;
        }
      }

      delete cur;
      cur = tmp;
    }

    int res = min_element(cur->begin(), cur->end())->first;
    delete cur;
    return res;
  }
};