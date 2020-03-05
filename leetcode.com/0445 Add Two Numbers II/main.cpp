#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 private:
  bool addTwoNumbersEqualLen(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return false;
    l1->val += addTwoNumbersEqualLen(l1->next, l2->next) + l2->val;
    bool carry = false;
    if (l1->val >= 10) {
      carry = true;
      l1->val -= 10;
    }
    return carry;
  }

 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int n1 = 0, n2 = 0;
    for (ListNode* p = l1; p; p = p->next) ++n1;
    for (ListNode* p = l2; p; p = p->next) ++n2;
    if (n1 < n2) {
      swap(n1, n2);
      swap(l1, l2);
    }
    stack<ListNode*> stk;
    ListNode* p = l1;
    for (int i = n1 - n2; i > 0; --i, p = p->next) stk.push(p);
    bool carry = addTwoNumbersEqualLen(p, l2);
    while (carry && !stk.empty()) {
      p = stk.top();
      stk.pop();
      p->val += carry;
      carry = false;
      if (p->val >= 10) {
        carry = true;
        p->val -= 10;
      }
    }
    if (carry) {
      p = new ListNode(1);
      p->next = l1;
      l1 = p;
    }
    return l1;
  }
};