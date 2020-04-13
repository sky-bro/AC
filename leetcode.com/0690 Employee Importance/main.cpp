#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// Employee info
class Employee {
 public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;
};

class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int, Employee*> m;
    for (auto e : employees) m.emplace(e->id, e);
    stack<Employee*> stk;
    stk.push(m[id]);
    int res = 0;
    while (!stk.empty()) {
      auto e = stk.top();
      stk.pop();
      res += e->importance;
      for (auto ee : e->subordinates) {
        stk.push(m[ee]);
      }
    }
    return res;
  }
};