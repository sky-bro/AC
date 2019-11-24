/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *p1=l1, *p2=l2, *head = new ListNode(0), *p3 = head;
        int carry = 0;
        for (;p1 && p2; p1 = p1->next, p2 = p2->next, p3 = p3->next){
            p3->next = new ListNode(p1->val + p2->val + carry);
            carry = p3->next->val / 10;
            p3->next->val %= 10;
        }
        if (p2){
            p1 = p2;
        }
        for (;p1;p1 = p1->next, p3 = p3->next) {
            p3->next = new ListNode(p1->val + carry);
            carry = p3->next->val / 10;
            p3->next->val %= 10;
        }
        if (carry) {
            p3->next = new ListNode(carry);
        }
        p3 = head->next;
        delete head;
        return p3;
    }
};
