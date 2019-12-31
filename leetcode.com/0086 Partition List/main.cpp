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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0);
        ListNode* cur_left = &left;
        ListNode right(0);
        ListNode* cur_right = &right;
        while (head) {
            if (head->val < x) {
                cur_left->next = new ListNode(head->val);
                cur_left = cur_left->next;
            } else {
                cur_right->next = new ListNode(head->val);
                cur_right = cur_right->next;
            }
            head = head->next;
        }
        cur_left->next = right.next;
        return left.next;
    }
};
