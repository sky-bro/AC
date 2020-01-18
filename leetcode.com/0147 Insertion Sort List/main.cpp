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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode head0(0); head0.next = head;
        for (ListNode *next_node = head; next_node && next_node->next; ) {
            ListNode *scanner = &head0;
            for (; scanner->next->val <= next_node->next->val && scanner != next_node; scanner = scanner->next);
            if (scanner != next_node) {
                ListNode *new_next_node = next_node->next->next;
                next_node->next->next = scanner->next;
                scanner->next = next_node->next;
                next_node->next = new_next_node;
                continue;
            }
            next_node = next_node->next;
        }
        return head0.next;
    }
};