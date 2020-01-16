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
        ListNode* cur = head;
        if(cur==NULL){
            return false;
        }
        while(true){
            if(cur->next == NULL){
                return false;
            }else if(cur->next <= cur){
                return true;
            }
            cur=cur->next;
        }
    }
};