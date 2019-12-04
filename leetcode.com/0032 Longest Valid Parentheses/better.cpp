#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string text) {
        stack<int> s;
        int maxlen = 0;
     
        s.push(-1);
        for(int i = 0; i<text.length(); i++){
            char ch = text[i];

            if(ch=='(')
                s.push(i);
            else if(ch==')'){
                s.pop();
                if(s.empty())
                    s.push(i);
                else
                    maxlen = max(maxlen, i-s.top());
            }
        }
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.longestValidParentheses(")()())")<<endl; // 4
    cout<<s.longestValidParentheses("()(()")<<endl; // 2
    return 0;
}
