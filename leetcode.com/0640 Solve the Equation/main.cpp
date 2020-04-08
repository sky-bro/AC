#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string solveEquation(string equation) {
    int x_cnt = 0;
    int sum = 0;
    bool is_positive = true;
    int i = 0, n = equation.length();
    while (equation[i] != '=') {
      if (equation[i] == '+') {
        ++i;
        is_positive = true;
      } else if (equation[i] == '-') {
        ++i;
        is_positive = false;
      } else if (equation[i] == 'x') {
        ++i;
        if (is_positive)
          ++x_cnt;
        else
          --x_cnt;
      } else {
        int num = 0;
        for (; equation[i] <= '9' && equation[i] >= '0'; ++i) {
          num = num * 10 + equation[i] - '0';
        }
        if (!is_positive) num *= -1;
        if (equation[i] == 'x') {
          x_cnt += num;
          ++i;
        } else
          sum -= num;
      }
    }

    ++i;
    is_positive = true;
    while (i < n) {
      if (equation[i] == '+') {
        ++i;
        is_positive = true;
      } else if (equation[i] == '-') {
        ++i;
        is_positive = false;
      } else if (equation[i] == 'x') {
        ++i;
        if (is_positive)
          --x_cnt;
        else
          ++x_cnt;
      } else {
        int num = 0;
        for (; equation[i] <= '9' && equation[i] >= '0'; ++i) {
          num = num * 10 + equation[i] - '0';
        }
        if (!is_positive) num *= -1;
        if (equation[i] == 'x') {
          x_cnt -= num;
          ++i;
        } else
          sum += num;
      }
    }

    if (x_cnt) return "x=" + to_string(sum / x_cnt);
    if (sum) return "No solution";
    return "Infinite solutions";
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string equation = "2x+3x-6x=x+2";  // x=-1
  while (cin >> equation) {
    cout << s.solveEquation(equation) << endl;
  }
  return 0;
}
