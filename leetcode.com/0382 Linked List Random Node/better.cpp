#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// ref:
// https://leetcode.com/problems/linked-list-random-node/discuss/85701/O(n)-Time-and-O(1)-Space-Java-Solution
class Solution {
 private:
  ListNode* head;

 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) { this->head = head; }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode *pnode = nullptr, *prev = head;
    for (int idx = 1; prev; ++idx) {
      if (rand() % idx == 0) pnode = prev;
      prev = prev->next;
    }
    return pnode->val;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */