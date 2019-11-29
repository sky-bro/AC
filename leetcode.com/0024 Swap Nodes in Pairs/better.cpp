#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode sentinel(0);
        ListNode* top = &sentinel;
        top->next = head;

        ListNode* item1;
        ListNode* item2;
        while((item1 = top->next) && (item2 = top->next->next)) {
            top->next = item1->next;
            item1->next = item2->next;
            item2->next = item1;
            top = item2->next;
        }
        return sentinel.next;
    }
};
