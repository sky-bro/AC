#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// dfs
class Solution {
 public:
  int lengthLongestPath(string input) {
    int cur_dir_len = 0, cur_path_len = 0, longest_path_len = 0;
    int tab_cnt = 0;
    int n = input.length();
    stack<int> dir_len;
    bool is_file = false;
    for (int i = 0; i < n; ++i) {
      if (input[i] == '\n') {
        // read \n\t...
        dir_len.push(cur_dir_len);
        cur_path_len += cur_dir_len;
        cur_dir_len = 0;

        int cur_tab_cnt = 0;
        for (; i + 1 < n && input[i + 1] == '\t'; ++i, ++cur_tab_cnt)
          ;
        if (cur_tab_cnt > tab_cnt)
          ++tab_cnt;
        else {
          if (is_file) {
            longest_path_len =
                max(longest_path_len, cur_path_len + int(dir_len.size() - 1));
            is_file = false;
          }
          for (++tab_cnt; tab_cnt > cur_tab_cnt; --tab_cnt) {
            cur_path_len -= dir_len.top();
            dir_len.pop();
          }
        }
      } else {
        // read single char
        if (input[i] == '.') is_file = true;
        ++cur_dir_len;
      }
    }
    if (is_file) {
      longest_path_len = max(longest_path_len,
                             cur_path_len + cur_dir_len + int(dir_len.size()));
      is_file = false;
    }
    return longest_path_len;
  }
};

int main(int argc, char const *argv[]) {
  string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";  // 20
  input =
      "dir\n\tsubdir1\n\t\tfile1."
      "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";  // 32
  input = "a";  // 0, no file
  Solution s;
  cout << s.lengthLongestPath(input) << endl;
  return 0;
}
