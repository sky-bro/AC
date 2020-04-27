#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MyCalendarThree {
 private:
  map<int, int> timeline;

 public:
  MyCalendarThree() {}
  int book(int start, int end) {
    ++timeline[start];
    --timeline[end];
    int ongoing = 0, res = 0;
    for (auto &p : timeline) {
      ongoing += p.second;
      res = max(res, ongoing);
    }
    return res;
  }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
