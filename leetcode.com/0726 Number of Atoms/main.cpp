#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  map<string, int> parse(const string &s, int &i) {
    map<string, int> atomCnt;
    while (i < n) {
      if (s[i] == '(') {
        map<string, int> subAtomCnt = parse(s, ++i);
        for (auto &p : subAtomCnt) {
          atomCnt[p.first] += p.second;
        }
      } else if (s[i] == ')') {
        int num = 0;
        for (++i; i < n && s[i] <= '9' && s[i] >= '0'; ++i) {
          num = num * 10 + s[i] - '0';
        }
        if (num) {
          for (auto &p : atomCnt) {
            p.second *= num;
          }
        }
        return atomCnt;
      } else {  // atom start
        string atom = "";
        atom.push_back(s[i++]);        // push_back first uppercase letter
        while (i < n && s[i] > 'Z') {  // lowercases
          atom.push_back(s[i++]);
        }
        int num = 0;
        for (; i < n && s[i] <= '9' && s[i] >= '0'; ++i) {
          num = num * 10 + s[i] - '0';
        }
        if (!num) num = 1;
        atomCnt[atom] += num;
      }
    }
    return atomCnt;
  }

 public:
  string countOfAtoms(string formula) {
    n = formula.size();
    int i = 0;
    map<string, int> atomCnt = parse(formula, i);
    string res = "";
    for (auto &p : atomCnt) {
      res.append(p.first);
      if (p.second > 1) res.append(to_string(p.second));
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.countOfAtoms(str) << endl;
  }
  return 0;
}
