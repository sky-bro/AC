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
        if (!head || !head->next) return head;
        ListNode* tmp = head->next;
        head->next = tmp->next;
        tmp->next = head;
        head->next = swapPairs(head->next);
        return tmp;
    }
};
