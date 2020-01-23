#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode head0(0); head0.next = head;
        for (ListNode* p = &head0; p->next;) {
            if (p->next->val == val) {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            } else {
                p = p->next;
            }
        }
        return head0.next;
    }
};