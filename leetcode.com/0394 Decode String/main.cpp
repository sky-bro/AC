#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    int n = s.length();
    int left_brackets_cnt = 0;
    stack<string> str_stk;
    str_stk.push("");  // cumulate
    stack<int> num_stk;
    for (int i = 0; i < n;) {
      if (isdigit(s[i])) {
        int num = s[i++] - '0';
        for (; isdigit(s[i]); ++i) {
          num *= 10;
          num += s[i] - '0';
        }
        num_stk.push(num);
        str_stk.push("");  // cumulate
        ++i;  // skip '[', (after num must be '[', '[' only appears after num)

      } else if (s[i] != ']') {
        // not digit, not '[' or ']'
        int len = 1;
        for (; i + len < n && !isdigit(s[i + len]) && s[i + len] != ']'; ++len)
          ;
        string new_top = str_stk.top() + s.substr(i, len);
        str_stk.pop();
        i += len;
        str_stk.push(new_top);
      } else {  // ']'
        ++i;
        int repeat = num_stk.top();
        num_stk.pop();
        string cur_str = str_stk.top();
        str_stk.pop();
        string new_top = str_stk.top();
        str_stk.pop();
        for (; repeat > 0; --repeat) {
          new_top += cur_str;
        }
        str_stk.push(new_top);
      }
    }
    return str_stk.top();
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s;
  while (cin >> s) {
    cout << sol.decodeString(s) << endl;
  }
  return 0;
}
