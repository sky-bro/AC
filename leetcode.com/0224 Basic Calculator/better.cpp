#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if ( s.empty() )
            return 0;
        
        int res = 0;
        stack<int> st;
        int num = 0;
        int sign = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            
            if (s[i] <= '9' && s[i] >= '0') {
                num = num * 10 + (s[i]-'0');
            } else if (s[i] == '+') {
                res += sign * num;
                sign = 1;
                num = 0;
            } else if (s[i] == '-') {
                res += sign * num;
                sign = -1;
                num = 0;
            } else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                sign = 1;
                num = 0;
                res = 0;
            } else if (s[i] == ')') {
                res += sign * num;
                res *= st.top();
                st.pop();
                res = st.top() + res;
                st.pop();
                sign = 1;
                num = 0;
            }
        }
        
        return res + sign * num;
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
