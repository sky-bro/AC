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
        ListNode *back = head, *p;
        while (back->next) {
            if (back->next->val == back->val) {
                p = back->next;
                back->next = p->next;
                delete p;
            } else {
                back = back->next;
            }
        }
        return head;
    }
};
