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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // task is to delete back->next
        ListNode root(0); root.next = head;
        ListNode* back = &root, *front = head;
        for (int i = 1; i < n; ++i, front = front->next);
        for (;front->next;front=front->next, back=back->next);
        ListNode *tmp = back->next;
        back->next = back->next->next;
        delete tmp;
        return root.next;
    }
};
