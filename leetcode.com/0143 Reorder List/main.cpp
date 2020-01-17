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
    void reorderList(ListNode* head) {
        ListNode *tmp = head;
        vector<ListNode*> vl;
        while (tmp) {
            vl.push_back(tmp);
            tmp = tmp->next;
        }
        int n = vl.size();
        ListNode head0(0);
        tmp = &head0;
        for (int l = 0, r = n-1; l < r; ++l, --r, tmp = tmp->next->next) {
            tmp->next = vl[l];
            tmp->next->next = vl[r];
        }
        if (n & 1) {
            tmp->next = vl[n/2];
            tmp = tmp->next;
        }
        tmp->next = nullptr;
    }
};