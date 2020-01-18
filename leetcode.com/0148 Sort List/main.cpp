#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        ListNode head0(0);
        ListNode* tmp = &head0;
        for (; head1 && head2; )
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                tmp->next = head1;
                tmp = head1;
                head1 = head1->next;
            } else {
                tmp->next = head2;
                tmp = head2;
                head2 = head2->next;
            }
        }
        if (head1) tmp->next = head1;
        else if (head2) tmp->next = head2;
        return head0.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }
};