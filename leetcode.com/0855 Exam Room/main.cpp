#include <iostream>
#include <set>

using namespace std;

class ExamRoom {
 private:
  set<int> seats;
  int n;

 public:
  ExamRoom(int N) {
    n = N;
    seats.clear();
  }

  int seat() {
    if (seats.empty()) {
      seats.insert(0);
      return 0;
    }
    int res = 0;
    int diff = (*seats.begin()) - 0;
    for (auto it = seats.begin(); it != seats.end(); ++it) {
      auto nit = next(it);
      if (nit == seats.end()) {
        if (n - 1 - (*it) > diff) {
          res = n - 1;
          seats.insert(res);
            return res;
        }
      }
      int tdiff = ((*nit) - (*it)) / 2;
      if (tdiff > diff) {
        diff = tdiff;
        res = diff + *it;
      }
    }
    seats.insert(res);
    return res;
  }

  void leave(int p) { seats.erase(p); }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

int main(int argc, char const *argv[]) {
  ExamRoom er(10);
  cout << er.seat() << endl;
  cout << er.seat() << endl;
  cout << er.seat() << endl;
  cout << er.seat() << endl;
  er.leave(4);
  cout << er.seat() << endl;
  return 0;
}
