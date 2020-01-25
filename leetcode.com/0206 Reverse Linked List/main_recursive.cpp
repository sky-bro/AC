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
private:
    ListNode* _reverseList(ListNode* head, ListNode* &rear) {
        if (!head->next) {
            rear = head;
            return head;
        }
        ListNode* tmp_head = _reverseList(head->next, rear);
        rear->next = head;
        rear = head;
        return tmp_head;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *rear;
        head = _reverseList(head, rear);
        rear->next = nullptr;
        return head;
    }
};