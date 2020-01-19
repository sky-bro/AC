#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> stk;
    MinStack() {
        
    }
    
    void push(int x) {
        if (stk.empty()) stk.push(pair<int, int>(x, x));
        else stk.push(pair<int, int>(x, min(x, stk.top().second)));
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};