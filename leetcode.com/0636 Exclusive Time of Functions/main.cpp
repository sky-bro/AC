#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <array>

using namespace std;

class Solution {
 private:
  void parseLog(const string& log, int& id, int& t, bool& isStart) {
    int i = log.find_first_of(':');
    id = stoi(log.substr(0, i));

    isStart = (log[i + 1] == 's');

    i = log.find_first_of(':', i + 1);
    t = stoi(log.substr(i + 1));
  }

 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res(n);
    int id, t;
    bool isStart;
    // id, start time, exclude time (end time won't be in stack)
    stack<array<int, 3>> stk;
    for (string& log : logs) {
      parseLog(log, id, t, isStart);
      if (isStart) {
        stk.push({id, t, 0});
      } else {
        auto p = stk.top();
        stk.pop();
        int diff = t - p[1] + 1;
        res[id] += diff - p[2];
        if (!stk.empty()) {
          p = stk.top();
          stk.pop();
          p[2] += diff;
          stk.push(p);
        }
      }
    }
    return res;
  }
};

template <typename T>
void printArr(const vector<T>& arr) {
  for (const T& t : arr) cout << t << " ";
  cout << endl;
}

int main(int argc, char const* argv[]) {
  Solution s;
  int n = 1;
  vector<string> logs = {"0:start:0", "0:start:1", "0:start:2",
                         "0:end:3",   "0:end:4",   "0:end:5"};
  printArr(s.exclusiveTime(n, logs));
  return 0;
}
