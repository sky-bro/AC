#include <iostream>
#include <map>  // <set>
#include <vector>

using namespace std;

class MyCalendar {
 private:
  map<int, int> m;

 public:
  MyCalendar() {}

  bool book(int start, int end) {
    if (m.empty()) {
      m.emplace(start, end);
      return true;
    }
    auto l = m.upper_bound(start);
    if (l != m.end() && end > l->first) return false;
    if (l != m.begin()) {
      if (start < (--l)->second) return false;
    }
    m.emplace(start, end);
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
