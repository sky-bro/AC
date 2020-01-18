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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* cur = dummy -> next;
        ListNode* prev = NULL;
        ListNode* tmp = NULL;
        
        while(cur != NULL && cur -> next != NULL){
            if(cur -> val <= cur -> next -> val){
                cur = cur -> next;
            }else{
                prev = dummy;
                tmp = cur -> next;
                cur -> next = cur -> next -> next;
                while(prev -> next -> val <= tmp -> val){
                    prev = prev -> next;
                }
                
                tmp -> next = prev -> next;
                prev -> next = tmp;
            }
        }
        return dummy -> next;
    }
};