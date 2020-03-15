#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
 private:
  int _maxSize;
  vector<pair<int, int>> stk;

 public:
  CustomStack(int maxSize) : _maxSize(maxSize) { stk.clear(); }

  void push(int x) {
    if (stk.size() < _maxSize) stk.emplace_back(x, 0);
  }

  int pop() {
    int sz = stk.size();
    if (sz == 0) return -1;
    int extra = stk[sz - 1].second, res = stk[sz - 1].first + extra;
    if (sz > 1) stk[sz - 2].second += extra;
    stk.pop_back();
    return res;
  }

  void increment(int k, int val) {
    int sz = stk.size();
    if (sz == 0) return;
    if (k >= sz)
      stk[sz - 1].second += val;
    else
      stk[k - 1].second += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */