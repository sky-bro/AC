#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  string build_str(vector<int>& digits) {
    string res = "";
    bool isfirst = true;
    for (int i = digits.size() - 1; i >= 0; --i) {
      if (digits[i] != -1) {
        if (isfirst && digits[i] == 0) {
          return "0";
        } else {
          isfirst = false;
        }
        res.push_back(digits[i] + '0');
      }
    }
    return res;
  }
  string dfs(vector<int>& digits, int cur_sum, int remain_cnt) {
    if (cur_sum % 3 == 0) {
      return build_str(digits);
    }
    string res = "";
    for (int i = 0; i < n; ++i) {
      if (digits[i] <= 0) continue;
      int digit = digits[i];
      digits[i] = -1;
      string tmp = dfs(digits, cur_sum - digit, remain_cnt - 1);
      digits[i] = digit;
      if (tmp.length() == remain_cnt - 1) {
        res = tmp;
        break;
      }
      if (res.length() < tmp.length() ||
          res.length() == tmp.length() && tmp > res) {
        res = tmp;
      }
      digits[i] = digit;
    }
    return res;
  }

 public:
  string largestMultipleOfThree(vector<int>& digits) {
    sort(digits.begin(), digits.end());  // digits in increasing order
    n = digits.size();
    if (digits[n - 1] == 0) return "0";
    int cur_sum = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
      cur_sum += digits[i];
    }

    return dfs(digits, cur_sum, n);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> digits = {1, 1, 1, 2};
  cout << s.largestMultipleOfThree(digits) << endl;
  return 0;
}
