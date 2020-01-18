#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        if (n == 0) return 0;
        int op1, op2;
        for (int i = 0; i < n; ++i) {
            if (tokens[i] == "+") {
                op1 = stk.top(); stk.pop();
                op2 = stk.top(); stk.pop();
                stk.push(op2 + op1);
            } else if (tokens[i] == "-") {
                op1 = stk.top(); stk.pop();
                op2 = stk.top(); stk.pop();
                stk.push(op2 - op1);
            } else if (tokens[i] == "*") {
                op1 = stk.top(); stk.pop();
                op2 = stk.top(); stk.pop();
                stk.push(op2 * op1);
            } else if (tokens[i] == "/") {
                op1 = stk.top(); stk.pop();
                op2 = stk.top(); stk.pop();
                stk.push(op2 / op1);
            } else {
                stk.push(atoi(tokens[i].c_str()));
            }
        }
        return stk.top();
    }
};