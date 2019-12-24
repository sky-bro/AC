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
    ListNode* deleteDuplicates(ListNode* head) {
        // basic idea: 
        // 1. use deamon to point head, corner case: 111112
        // 2. use deamon record last repeat value, 
        //    so it can handle multi-duplicate, corner case: 12223334
        
        // NULL case
        if (!head)
            return head;

        
        ListNode* deamon = new ListNode(0);
        deamon->next = head;
    
        ListNode* last = deamon;
        while (last->next) {
            
            ListNode* cur = last->next;
            
            // if duplicated, move to next, until distinct or reach end
            while (cur->next && cur->next->val == cur->val) {
                cur = cur->next;
            }
            
            // duplicated exist
            if (cur != last->next) {
                last->next = cur->next;
            } else { // duplicated not exist
                last = cur;
            }
        }
        
        return deamon->next;
        
    }
};

