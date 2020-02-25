#include <iostream>
#include <vector>

using namespace std;

// ref: Here is a 10-line template that can solve most 'substring' problems
// https://leetcode.com/problems/minimum-window-substring/discuss/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> tmap(128, 0);
    for (auto ch : t) tmap[ch]++;

    int begin = 0, end = 0, ret = INT32_MAX, count = t.size(), head;

    while (end < s.size()) {
      if (tmap[s[end++]]-- > 0) count--;

      while (count == 0) {
        if (ret > end - begin) {
          ret = end - begin;
          head = begin;
        }

        if (tmap[s[begin++]]++ >= 0) count++;
      }
    }

    return ret == INT32_MAX ? "" : s.substr(head, ret);
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s, t;
  while (cin >> s >> t) cout << sol.minWindow(s, t) << endl;
  return 0;
}
