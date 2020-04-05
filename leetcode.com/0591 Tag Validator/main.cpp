#include <iostream>
#include <regex>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/tag-validator/discuss/103370/Short-Python-accepted-but-not-sure-if-correct
// ref: https://deerchao.cn/tutorials/regex/regex.htm

class Solution {
 public:
  bool isValid(string code) {
    if (code == "t") return false;
    // regex tag_pattern(R"(<(?<TAGNAME>[A-Z]{1,9})>[^<]*</\k<TAGNAME>>)");
    regex tag_pattern(R"(<([A-Z]{1,9})>[^<]*</\1>)");
    regex cdata_pattern(R"(<!\[CDATA\[.*?\]\]>)");
    code = regex_replace(code, cdata_pattern, "c");
    string prev = "";
    while (code != prev) {
      prev = code;
      code = regex_replace(code, tag_pattern, "t");
    }
    return code == "t";
  }
};

/*
"<DIV>This is the first line <![CDATA[<div>]]></DIV>"
"<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
"<A>  <B> </A>   </B>"
"<DIV>  div tag is not closed  <DIV>"
"<DIV>  unmatched <  </DIV>"
"<DIV> closed tags with invalid tag name  <b>123</b> </DIV>"
"<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>
</DIV>"
"<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>"
*/

int main(int argc, char const *argv[]) {
  Solution s;
  string code;
  while (getline(cin, code)) {
    cout << s.isValid(code) << endl;
  }
  return 0;
}
