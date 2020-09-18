#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
      pA = pA ? pA->next : pB;
      pB = pB ? pB->next : pA;
    }
    return pA;
  }
};
