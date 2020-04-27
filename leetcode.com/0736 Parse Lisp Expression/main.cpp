#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  int n;
  unordered_map<string, int> variables;
  string getVarName(const string &exp, int &i) {
    int len = 0;
    while (i < n && ((exp[i] <= 'z' && exp[i] >= 'a') || (exp[i] <= '9' && exp[i] >= '0'))) { // i < n not needed ?
      ++len;
      ++i;
    }
    return exp.substr(i-len, len);
  }
  int evalItem(const string &exp, int &i, string &varName) {
    if (exp[i] == '(') { // add, mult, let
      ++i;
      if (exp[i] == 'l') { // let
        unordered_map<string, int> variables_bak = variables;
        int res = -1;
        i += 4; // "let "
        while (true) { // let express ends with ')'
          res = evalItem(exp, i, varName); // key or expression
          if (exp[i++] == ')') break; // ')' or ' '
          string key = varName;
          variables[key] = evalItem(exp, i, varName); // value
          ++i; // space;
        }
        variables = variables_bak;
        return res;
      } else { // add, mult
        bool isAdd = exp[i] == 'a';
        i += (isAdd ? 4 : 5);
        int a = evalItem(exp, i, varName);
        ++i; // a space " "
        int b = evalItem(exp, i, varName);
        ++i; // ")"
        return isAdd ? a + b : a * b;
      }
    } else if ((exp[i] <= '9' && exp[i] >= '0') || exp[i] == '-') { // num
      int res = 0;
      int flag = exp[i] == '-' ? ++i, -1 : 1;
      while (i < n && exp[i] <= '9' && exp[i] >= '0') {
        res = res * 10 + exp[i++] - '0';
      }
      return res * flag;
    } else { // variable
      varName = getVarName(exp, i);
      return variables[varName];
    }
  }
public:
    int evaluate(string expression) {
      n = expression.length();
      int i = 0;
      variables.clear();
      string varName;
      return evalItem(expression, i, varName);
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  string str;
  while (getline(cin, str)) cout<<s.evaluate(str)<<endl;
  return 0;
}
