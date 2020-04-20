#include <iostream>
#include <vector>

using namespace std;

struct ListNode2 {
  int val;
  ListNode2 *prev;
  ListNode2 *next;
  ListNode2(int x) : val(x), prev(NULL), next(NULL) {}
  ListNode2(int x, ListNode2 *_prev, ListNode2 *_next) : val(x), prev(_prev), next(_next) {}
  ~ListNode2() {
    if (prev) prev->next = next;
    if (next) next->prev = prev;
  }
};

class MyLinkedList {
 private:
  ListNode2 *head, *tail;

 public:
  /** Initialize your data structure here. */
  MyLinkedList() { head = tail = nullptr; }

  ~MyLinkedList() {
    while (head) {
      ListNode2* tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    ListNode2 *cur = head;
    while (cur && index) {cur = cur->next; --index;}
    return cur ? cur->val : -1;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    if (!head) {
      head = tail = new ListNode2(val);
      return;
    }
    head = head->prev = new ListNode2(val, nullptr, head);
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    if (!head) {
      head = tail = new ListNode2(val);
      return;
    }
    tail = tail->next = new ListNode2(val, tail, nullptr);
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (index == 0) {
      addAtHead(val);
      return;
    }
    --index;
    ListNode2 *cur = head;
    while (index && cur) {cur = cur->next;--index;}
    if (!cur) return;
    ListNode2 *tmp = cur->next = new ListNode2(val, cur, cur->next);
    if (tmp->next)
      tmp->next->prev = tmp;
    else
      tail = tmp;
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    ListNode2 *cur = head;
    while (index && cur) {cur = cur->next;--index;}
    if (!cur) return;
    if (cur == head) head = head->next;
    if (cur == tail) tail = tail->prev;
    delete cur;
  }
};

int main(int argc, char const *argv[]) {
  // ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
  // [[],[1],[3],[1,2],[1],[1],[1]]
  MyLinkedList l;
  l.addAtHead(1);
  l.addAtTail(3);
  l.addAtIndex(1, 2);
  cout << l.get(1) << '\n';
  l.deleteAtIndex(1);
  cout << l.get(1) << '\n';
  return 0;
}
