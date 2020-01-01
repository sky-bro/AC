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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode root(0); root.next = head;
        ListNode *left = &root, *right = left->next;
        for (int i = 1; i < m; left = left->next, right = right->next, ++i);
        for (int i = 0; i < n - m; ++i) {
            ListNode *tmp = left->next;
            left->next = right->next;
            right->next = right->next->next;
            left->next->next = tmp;
        }
        return root.next;
    }
};
