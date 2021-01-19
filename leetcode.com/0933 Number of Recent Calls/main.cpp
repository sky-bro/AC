#include <iostream>
#include <vector>

using namespace std;

class RecentCounter {
 private:
  vector<int> calls;

 public:
  RecentCounter() {}

  int ping(int t) {
    calls.push_back(t);
    return calls.end() - lower_bound(calls.begin(), calls.end(), t - 3000);
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
