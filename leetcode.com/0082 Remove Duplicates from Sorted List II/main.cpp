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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode root(0);
        root.next = head;
        
        for (ListNode *p = &root; p->next;) {
            ListNode *q = p->next;
            if (!q->next || q->next->val != q->val) {
                p = p->next;
                continue;
            }
            int pre_val = q->val;
            for (; q && q->val == pre_val; q = p->next) {
                p->next = q->next;
                delete q;
            }
        }
        return root.next;
    }
};
