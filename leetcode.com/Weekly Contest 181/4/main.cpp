#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  string longestPrefix(string s) {
    int n = s.length();
    vector<int> arr(n);
    int len = 0;
    for (int i = 1; i < n;) {
      if (s[len] == s[i]) {
        arr[i++] = ++len;
      } else {
        if (len != 0) {
          len = arr[len - 1];
        } else {
          arr[i] = 0;
          i++;
        }
      }
    }
    cout << arr[n - 1] << endl;
    return s.substr(0, arr[n - 1]);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str = "ababab";
  while (cin >> str) {
    cout << s.longestPrefix(str) << endl;
  }
  return 0;
}
