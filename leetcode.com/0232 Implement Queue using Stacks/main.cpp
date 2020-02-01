#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> *stk1, *stk2;
    bool front_on_top;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        stk1 = new stack<int>;
        stk2 = new stack<int>;
        front_on_top = false;
    }

    ~MyQueue() {
        delete stk1;
        delete stk2;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (!front_on_top) {
            stk1->push(x);
            return;
        }
        while (!(stk1->empty())) {
            stk2->push(stk1->top());
            stk1->pop();
        }
        swap(stk1, stk2);
        stk1->push(x);
        front_on_top = false;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!front_on_top) {
             while (!(stk1->empty()))
            {
                stk2->push(stk1->top());
                stk1->pop();
            }
            swap(stk1, stk2);
        }

        int result = stk1->top(); stk1->pop();
        front_on_top = true;
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if (!front_on_top) {
             while (!(stk1->empty()))
            {
                stk2->push(stk1->top());
                stk1->pop();
            }
            swap(stk1, stk2);
        }

        int result = stk1->top();
        front_on_top = true;
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1->empty();
    }

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */