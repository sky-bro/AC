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
        if (!head) return nullptr;
        ListNode* next = head->next;
        head->next = nullptr;
        while (next) {
            ListNode* tmp = next->next;
            next->next = head;
            head = next;
            next = tmp;

        }
        return head;
    }
};