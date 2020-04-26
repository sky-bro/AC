#include <iostream>
#include <map>  // <set>
#include <vector>

using namespace std;

// ref: [Java/C++] Clean Code with Explanation
// https://leetcode.com/problems/my-calendar-ii/discuss/109519/JavaC%2B%2B-Clean-Code-with-Explanation

// just bf, at most 1000 books
class MyCalendar {
 private:
  vector<pair<int, int>> books;

 public:
  bool book(int start, int end) {
    for (pair<int, int> &p : books)
      if (max(p.first, start) < min(end, p.second)) return false;
    books.emplace_back(start, end);
    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
