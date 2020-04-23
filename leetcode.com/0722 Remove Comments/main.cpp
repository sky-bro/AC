#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        enum State {NoComment, OpenBlockComment};
        State cur_state = NoComment;
        vector<string> res;
        for (string line: source) {
          int i = 0, len = line.length(); 
          if (len == 0) continue;
          string row = "";
          if (cur_state == OpenBlockComment) {
            int idx = line.find("*/");
            if (idx == -1) {
              continue;
            } else {
              row = res.back();
              res.pop_back();
              i = idx + 2;
              cur_state = NoComment;
            }
          }
          for (;i < len;++i) {
            if (line[i] == '/') {
              if (i+1 >= len) row.push_back('/');
              else if (line[i+1] == '/') {
                break;
              } else if (line[i+1] == '*') {
                int r = line.find("*/", i+2);
                if (r == -1) {
                  cur_state = OpenBlockComment;
                  break;
                }
                i = r+1;
              } else row.push_back('/');
            } else row.push_back(line[i]);
          }
          if (!row.empty() || cur_state == OpenBlockComment) res.push_back(row);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<string> source = {"/*a*/b/*c*/"};
  source = {"void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}"};
  printArr(s.removeComments(source));
  return 0;
}
