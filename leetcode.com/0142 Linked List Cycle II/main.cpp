// https://leetcode.com/problems/linked-list-cycle-ii/discuss/480759/Super-easy-to-understand-code-and-math-proof-really!
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *old_head = head;
        head = head->next;
        ListNode *fast_head = head->next;
        for (; fast_head && fast_head->next && fast_head != head; head = head->next, fast_head = fast_head->next->next);
        if (head != fast_head) return nullptr;
        while (old_head != head) {
            old_head = old_head->next;
            head = head->next;
        }
        return head;
    }
};