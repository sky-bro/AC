#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// sol 1: https://leetcode.com/problems/palindrome-linked-list/discuss/409788/C%2B%2B-Beats-100-on-Runtime-(with-Explanation)
// sol 2: https://leetcode.com/problems/palindrome-linked-list/discuss/407996/c%2B%2B-easy-to-understand-solution-O(n)-time-O(1)-space-faster-than-91.56
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !(head->next)) return true;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) {
            fast = slow->next;
        } else {
            fast = slow;
        }
        slow = head;

        ListNode *pnode = fast->next;
        fast->next = nullptr;
        while (pnode) {
            ListNode *tmp = pnode->next;
            pnode->next = fast;
            fast = pnode;
            pnode = tmp;
        }

        while (fast) {
            if (fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }

        return true;
    }
};