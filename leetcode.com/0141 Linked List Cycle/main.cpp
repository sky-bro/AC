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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *head_fast = head->next->next;
        head = head->next;
        for (; head_fast && head_fast->next && head != head_fast && head != head_fast; head_fast = head_fast->next->next, head = head->next);
        return head == head_fast;
    }
};