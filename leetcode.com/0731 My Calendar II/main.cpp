#include <iostream>
#include <vector>
#include <map>

using namespace std;

// ref: [Java/C++] Clean Code with Explanation
// https://leetcode.com/problems/my-calendar-ii/discuss/109519/JavaC%2B%2B-Clean-Code-with-Explanation

// reuse MyCalendar implementation
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

class MyCalendarTwo {
private:
  vector<pair<int,int>> books;
public:
    bool book(int start, int end) {
      MyCalendar overlaps;
      for (auto &p: books) {
        int s = max(p.first, start), e = min(p.second, end);
        if (s < e) {
          if (!overlaps.book(s, e)) return false;
        }
      }
      books.emplace_back(start, end);
      return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
