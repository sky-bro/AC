#include <iostream>
#include <stack>

using namespace std;

struct Node{
    char c;
    int max_len;
    Node(char _c, int _max_len): c(_c), max_len(_max_len){}
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        stack<Node> stk;
        stk.push(Node(0, 0));
        int max_len = 0;
        for (char c: s) {
            Node t = stk.top();
            if (c == '(') {
                stk.push(Node('(', 0));
            } else if (t.c == '(') {
                stk.pop();
                Node t1 = stk.top();
                stk.pop();
                t1.max_len += t.max_len + 2;
                stk.push(t1);

                if (t1.max_len > max_len) max_len = t1.max_len;
            } else {
                stk.push(Node(')', 0));
            }
        }
        return max_len;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.longestValidParentheses(")()())")<<endl; // 4
    cout<<s.longestValidParentheses("()(()")<<endl; // 2
    return 0;
}
