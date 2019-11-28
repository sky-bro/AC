#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.push('X');
        for (auto c: s) {
            switch (c) {
            case ')':
                if (stk.top() == '(') {
                    stk.pop();
                } else return false;
                break;
            case ']':
                if (stk.top() == '[') {
                    stk.pop();
                } else return false;
                break;
            case '}':
                if (stk.top() == '{') {
                    stk.pop();
                } else return false;
                break;
            default: 
                stk.push(c);
            }
        }
        if (stk.top() == 'X') return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
