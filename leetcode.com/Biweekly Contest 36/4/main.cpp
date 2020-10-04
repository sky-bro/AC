#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define fi first
#define se second
#define ins insert
#define pb push_back

class Solution {
 public:
  vector<int> busiestServers(int k, vector<int>& a, vector<int>& b) {
    set<int> r;
    for (int i = 0; i < k; i++) r.insert(i);
    priority_queue<pair<int, int> > bsy;
    int Q = a.size();
    map<int, int> res;
    for (int i = 0; i < Q; i++) {
      int pos = i % k;
      int tim = a[i];
      int lod = b[i];
      while (!bsy.empty() && bsy.top().fi * -1 <= tim) {
        r.insert(bsy.top().se);
        bsy.pop();
      }
      if (r.empty())
        continue;
      else {
        auto itr = r.lower_bound(pos);
        if (itr == r.end()) itr = r.begin();
        pos = *itr;
        r.erase(pos);
        res[pos] += 1;
        bsy.push(make_pair(-a[i] - b[i], pos));
      }
    }
    int mx = 0;
    for (auto it : res) {
      mx = max(mx, it.se);
    }
    vector<int> vec;
    for (auto it : res) {
      if (it.se == mx) vec.pb(it.fi);
    }
    return vec;
  }
};