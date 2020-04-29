#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> _q1, _q2;
        unordered_set<string> dead(deadends.begin(), deadends.end()), _vis1, _vis2;

        queue<string> *q1 = &_q1, *q2 = &_q2;
        unordered_set<string> *vis1 = &_vis1, *vis2 = &_vis2;
        // corner cases
        if (dead.count("0000") || dead.count(target)) return -1;
        else if (target == "0000") return 0;

        int steps = 0;
        (*q1).push("0000");
        (*q2).push(target);
        (*vis1).insert("0000");
        (*vis2).insert(target);

        while (!q1->empty() && !q2->empty()) {
          ++steps;
          if (q1->size() > q2->size()) {
            swap(q1, q2);
            swap(vis1, vis2);
          }
          for (int sz = q1->size(); sz > 0; --sz){
          string pre_str = q1->front(); q1->pop();
          for (int i = 0; i < 4; ++i) {
            string cur_str = pre_str;
            cur_str[i] = cur_str[i] == '0' ? '9' : cur_str[i]-1;
            if (vis2->count(cur_str)) return steps;
            if (vis1->count(cur_str) == 0 && dead.count(cur_str) == 0) {
              q1->push(cur_str);
              vis1->insert(cur_str);
            }

            cur_str = pre_str;
            cur_str[i] = cur_str[i] == '9' ? '0' : cur_str[i]+1;
            if (vis2->count(cur_str)) return steps;
            if (vis1->count(cur_str) == 0 && dead.count(cur_str) == 0) {
              q1->push(cur_str);
              vis1->insert(cur_str);
            }
          }}
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<string> deadends = {"0201","0101","0102","1212","2002"};
  string target = "0202";
  cout<<s.openLock(deadends, target)<<endl;
  return 0;
}
