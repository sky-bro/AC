#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
private:
    int n;

    inline void skip_spaces(const string &s, int &idx) {
        while (idx < n && isspace(s[idx])) ++idx;
    }

    int factor(const string &s, int &idx) {
        skip_spaces(s, idx);
        int result = 0;
        if (idx < n) {
            if (s[idx] == '(') {
                ++idx;
                result = exp(s, idx);
                ++idx;
            } else {
                int len;
                sscanf(s.c_str() + idx, "%d%n", &result, &len);
                idx += len;
            }
        }
        return result;
    }

    int term(const string &s, int &idx) {
        int result = factor(s, idx);
        skip_spaces(s, idx);
        while (idx < n) {
            if (s[idx] == '*') {
                ++idx;
                result *= factor(s, idx);
            } else if (s[idx] == '/') {
                ++idx;
                result /= factor(s, idx);
            } else break; // ')' '+' '-'
            skip_spaces(s, idx);
        }
        return result;
    }

    int exp(const string &s, int &idx) {
        int result = term(s, idx);
        skip_spaces(s, idx);
        while (idx < n) {
            if (s[idx] == '+') {
                ++idx;
                result += term(s, idx);
            } else if (s[idx] == '-') {
                ++idx;
                result -= term(s, idx);
            } else break; // ')'
            skip_spaces(s, idx);
        }
        return result;
    }
public:
    int calculate(string s) {
        n = s.length();
        int idx = 0;
        return exp(s, idx);
    }
};


int main(int argc, char const *argv[])
{
    string str;
    Solution s;
    while (cin>>str) {
        cout<<s.calculate(str)<<endl;
    }
    return 0;
}
