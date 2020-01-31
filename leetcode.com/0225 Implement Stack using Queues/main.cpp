#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> *q1, *q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        q1 = new queue<int>();
        q2 = new queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        (*q1).push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if ((*q1).empty()) return -1;
        while ((*q1).size() != 1) {
            (*q2).push((*q1).front());
            (*q1).pop();
        }
        int top_val = (*q1).front(); (*q1).pop();
        swap(q1, q2);
        return top_val;
    }
    
    /** Get the top element. */
    int top() {
        if ((*q1).empty()) return -1;
        while ((*q1).size() != 1) {
            (*q2).push((*q1).front());
            (*q1).pop();
        }
        int top_val = (*q1).front(); (*q1).pop();
        (*q2).push(top_val);
        swap(q1, q2);
        return top_val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (*q1).empty();
    }

    ~MyStack() {
        delete q1;
        delete q2;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */