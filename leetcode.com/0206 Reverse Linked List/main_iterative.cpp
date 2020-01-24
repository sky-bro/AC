#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stk;
        while (head) {
            stk.push(head);
            head = head->next;
        }
        ListNode head0(0);
        ListNode *tmp = &head0;
        while (!stk.empty()) {
            tmp->next = stk.top(); stk.pop();
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        return head0.next;
    }
};