#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
 public:
  Node* flatten(Node* head) {
    if (!head) return nullptr;
    stack<Node*> stk;
    stk.push(head);
    Node root;
    Node* pre = &root;
    while (!stk.empty()) {
      Node* cur = stk.top();
      stk.pop();
      if (cur->next) {
        stk.push(cur->next);
      }
      pre->next = cur;
      cur->prev = pre;
      pre = cur;
      if (cur->child) {
        stk.push(cur->child);
        cur->child = nullptr;
      }
    }
    pre->next = nullptr;
    head->prev = nullptr;
    return head;  // root->next
  }
};