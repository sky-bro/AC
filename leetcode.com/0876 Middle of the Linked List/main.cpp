#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) return head;
        head = head->next;
        ListNode*fast = head->next;
        while (fast && fast->next) {
          head = head->next;
          fast = fast->next->next;
        }
        return head;
    }
};