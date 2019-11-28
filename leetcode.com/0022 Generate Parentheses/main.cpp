#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    vector<string> res;
    void gen_parenthesis(stack<char> &stk, string &cur_str, int left_n, int right_n){
        char c = stk.top();
        switch (c)
        {
        case '(':
            if (right_n){
                stk.pop();
                cur_str.push_back(')');
                gen_parenthesis(stk, cur_str, left_n, right_n-1);
                stk.push('(');
                cur_str.pop_back();
            }
            
            if (left_n) {
                stk.push('(');
                cur_str.push_back('(');
                gen_parenthesis(stk, cur_str, left_n-1, right_n);
                stk.pop();
                cur_str.pop_back();
            }
            break;
        case ')':
            if (right_n){
                stk.push(')');
                cur_str.push_back(')');
                gen_parenthesis(stk, cur_str, left_n, right_n-1);
                stk.pop();
                cur_str.pop_back();
            }
            
            if (left_n) {
                stk.push('(');
                cur_str.push_back('(');
                gen_parenthesis(stk, cur_str, left_n-1, right_n);
                stk.pop();
                cur_str.pop_back();
            }
            break;
        default:
            if (left_n) {
                stk.push('(');
                cur_str.push_back('(');
                gen_parenthesis(stk, cur_str, left_n-1, right_n);
                stk.pop();
                cur_str.pop_back();
            } else {
                res.push_back(cur_str);
            }
            break;
        } 
    }
public:
    vector<string> generateParenthesis(int n) {
        if (!n) return vector<string>(0);
        string cur_str = "";
        stack<char> stk;
        stk.push('X');
        gen_parenthesis(stk, cur_str, n, n);
        return res;
    }
};
