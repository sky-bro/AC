#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char** argv) {
    stack<string> stk;
    string s;
    while (cin>>s) {
        stk.push(s);
    }
    while (!stk.empty()) {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    return 0;
}