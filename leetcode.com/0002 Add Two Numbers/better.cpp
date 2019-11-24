// https://leetcode.com/problems/add-two-numbers/discuss/436802/98-CPP-c%2B%2B-solution
/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(0), *cur = ret;
        int v1, v2, total, carry=0;

        while(l1 || l2 || carry){
            v1 = 0;
            v2 = 0;
            if (l1){
                v1 = l1->val;
                l1 = l1->next;
            }
            if (l2){
                v2 = l2->val;
                l2 = l2->next;
            }
            total = v1 + v2 + carry;
            carry = total/10;
            total %= 10;
            cur->next = new ListNode(total);
            cur = cur->next;
        }

        cur = ret->next;
        delete ret;
        return cur;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
