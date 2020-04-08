#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
 private:
  struct Node {
    int val;
    Node *prev, *next;
    Node(int _val, Node *_prev = nullptr, Node *_next = nullptr)
        : val(_val), prev(_prev), next(_next) {}
  };
  int cap;
  int sz;
  Node *head, *tail;

 public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k) : cap(k), sz(0), head(nullptr), tail(nullptr) {}

  /** Adds an item at the front of Deque. Return true if the operation is
   * successful. */
  bool insertFront(int value) {
    if (sz >= cap) return false;
    if (++sz == 1) {
      head = tail = new Node(value);
      return true;
    }
    head->prev = new Node(value, nullptr, head);
    head = head->prev;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is
   * successful. */
  bool insertLast(int value) {
    if (sz >= cap) return false;
    if (++sz == 1) {
      head = tail = new Node(value);
      return true;
    }
    tail->next = new Node(value, tail);
    tail = tail->next;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is
   * successful. */
  bool deleteFront() {
    if (!head) return false;
    if (--sz == 0) {
      delete head;
      head = tail = nullptr;
      return true;
    }
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is
   * successful. */
  bool deleteLast() {
    if (!tail) return false;
    if (--sz == 0) {
      delete tail;
      head = tail = nullptr;
      return true;
    }
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    return true;
  }

  /** Get the front item from the deque. */
  int getFront() {
    if (!head) return -1;
    return head->val;
  }

  /** Get the last item from the deque. */
  int getRear() {
    if (!tail) return -1;
    return tail->val;
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() { return sz == 0; }

  /** Checks whether the circular deque is full or not. */
  bool isFull() { return sz >= cap; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */