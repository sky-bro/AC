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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head || !(head->next)) return head;

        ListNode *back = head, *front = head;
        int n = 1;
        for (; back->next; back = back->next, ++n);
        k %= n;

        back->next = head;
        for (int i = 0; i < k; ++i, front = front->next);
        while (front != head) {
            back = back->next;
            front = front->next;
        }
        front = back->next;
        back->next = nullptr;
        return front;
    }
};
