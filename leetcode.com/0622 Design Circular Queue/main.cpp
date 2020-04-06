#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int i, j, k;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k+1);
        i = j = 0;
        this->k= k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        q[j] = value;
        j = (j + 1) % (k + 1);
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        i = (i + 1) % (k + 1);
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return q[i];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return q[(j+k)%(k+1)];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return i == j;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (j+1)%(k+1)== i;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */