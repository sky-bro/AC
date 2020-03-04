#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

uint16_t str2u16(const string& str) {
  // A G C T
  // 0 1 2 3
  uint16_t res = 0;
  for (char c : str) {
    res <<= 2;
    if (c == 'G')
      res += 1;
    else if (c == 'C')
      res += 2;
    else if (c == 'T')
      res += 3;
  }
  return res;
}

class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    uint16_t start_num = str2u16(start);
    uint16_t end_num = str2u16(end);
    unordered_set<uint16_t> bank_num;  // nums haven't been visited
    transform(bank.begin(), bank.end(), inserter(bank_num, nullptr),
              [](const string& str) { return str2u16(str); });

    // corner case
    if (bank_num.find(end_num) == bank_num.end()) return -1;
    if (start_num == end_num) return 0;
    bank_num.erase(start_num);  // erase visited num
    bank_num.erase(end_num);    // erase visited num

    int res = 1;
    // two-way bfs
    queue<uint16_t> _q1, _q2, *q1 = &_q1, *q2 = &_q2;
    _q1.push(start_num);
    _q2.push(end_num);
    unordered_set<uint16_t> _level1, _level2, *level1 = &_level1,
                                              *level2 = &_level2;
    _level2.insert(end_num);

    while (!q1->empty()) {
      for (int sz = q1->size(); sz > 0; --sz) {
        uint16_t num = q1->front();
        q1->pop();

        // modify 1 bit at a time
        uint16_t mask = 1;
        for (int i = 0; i < 16; ++i) {
          int next_num = num ^ mask;
          if (bank_num.find(next_num) != bank_num.end()) {
            q1->push(next_num);
            bank_num.erase(next_num);
            level1->insert(next_num);
          } else if (level2->find(next_num) != level2->end()) {
            return res;
          }
          mask <<= 1;
        }

        // modify 2 bits at a time
        mask = 3;
        for (int i = 0; i < 8; ++i) {
          int next_num = num ^ mask;
          if (bank_num.find(next_num) != bank_num.end()) {
            q1->push(next_num);
            bank_num.erase(next_num);
            level1->insert(next_num);
          } else if (level2->find(next_num) != level2->end()) {
            return res;
          }
          mask <<= 2;
        }
      }

      ++res;
      // prepare for the next round
      if (q1->size() > q2->size()) {
        swap(q1, q2);
        swap(level1, level2);
      }
      level1->clear();
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string start = "AACCGGTT", end = "AACCGGTA";
  vector<string> bank = {"AACCGGTA"};
  cout << s.minMutation(start, end, bank) << endl;
  return 0;
}
