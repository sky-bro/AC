#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int calPoints(vector<string>& ops) {
    vector<int> scores;
    int n = 0, sum = 0;
    for (const string& op : ops) {
      if (op == "C") {
        sum -= scores.back();
        scores.pop_back();
        --n;
      } else if (op == "D") {
        scores.push_back(scores.back()*2);
        sum += scores.back();
        ++n;
      } else if (op == "+") {
        scores.push_back(scores[n-1]+scores[n-2]);
        sum += scores.back();
        ++n;
      } else {
        scores.push_back(stoi(op));
        sum += scores.back();
        ++n;
      }
    }
    return sum;
  }
};