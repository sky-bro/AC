#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int res = 0;
    for (string& log : logs) {
      if (log == "../")
        res = max(0, res - 1);
      else if (log != "./")
        ++res;
    }
    return res;
  }
};
