#include <iostream>
#include <stack>

using namespace std;

// basic, read from left to right
class Solution {
private:
    void read_str(stack<char>  &stk, string &s) {
        for (char c: s) {
            if (c != '#') stk.push(c);
            else if (!stk.empty()) {
                stk.pop();
            }
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stk1, stk2;
        read_str(stk1, S);
        read_str(stk2, T);
        if (stk1.size() != stk2.size()) return false;
        while (!stk1.empty()) {
            if (stk1.top() != stk2.top()) return false;
            stk1.pop();
            stk2.pop();
        }
        return true;
    }
};