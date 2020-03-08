#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string sortString(string s) {
    int cnt[26]{};
    for (char c : s) cnt[c - 'a']++;
    string res = "";
    int n = s.length();
    while (n) {
      for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
          --cnt[i];
          res.push_back(i + 'a');
          --n;
        }
      }
      for (int i = 25; i >= 0; --i) {
        if (cnt[i]) {
          --cnt[i];
          res.push_back(i + 'a');
          --n;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str = "rat";
  cout << s.sortString(str) << endl;
  return 0;
}
