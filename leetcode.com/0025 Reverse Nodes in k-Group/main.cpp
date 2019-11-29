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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // if (k == 1) return head;
        ListNode root(0), *back = &root, *front = &root, *tmp, *tmp2;
        root.next = head;
        
        while (front) {
            int tmpi = 0;
            for (; tmpi < k && front; ++tmpi) front = front->next;
            if (!front) return root.next;
            tmp = back->next;
            while (back != front) {
                tmp2 = back->next;
                back->next = tmp2->next;
                tmp2->next = front->next;
                front->next = tmp2;
            }
            front = back = tmp;
        }
        return root.next;
    }
};
