#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 private:
  ListNode* head;
  int n;

 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) {
    this->head = head;
    n = 0;
    while (head) {
      head = head->next;
      ++n;
    }
  }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode* pnode = head;
    for (int idx = rand() % n; idx > 0; --idx) {
      pnode = pnode->next;
    }
    return pnode->val;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */