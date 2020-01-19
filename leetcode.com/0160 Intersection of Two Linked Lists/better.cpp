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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int d = 0;
        for(auto p = headA; p != nullptr; p = p->next)
            d++;
        for(auto p = headB; p != nullptr; p = p->next)
            d--;
        auto p1 = headA, p2 = headB;
        for(; d > 0; --d)
            p1 = p1->next;
        for(; d < 0; ++d)
            p2 = p2->next;
        while(p1 != nullptr){
            if(p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};