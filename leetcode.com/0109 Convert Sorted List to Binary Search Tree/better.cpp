#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
            return NULL;
        if(!head->next) 
            return new TreeNode(head->val);
        
        ListNode* slow=head; ListNode* fast=head;
        ListNode* prev=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //break the list into 2 halves
        prev->next=NULL;
        
        TreeNode* root=new TreeNode(slow->val);
        
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        return root;
        
    }
};