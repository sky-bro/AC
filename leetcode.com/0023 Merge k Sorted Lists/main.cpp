#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp //重写仿函数
{
    bool operator() (ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (auto l: lists){
            if (l) q.push(l);
        }
        ListNode root(0), *p=&root, *tmp;
        while (!q.empty()){
            tmp = q.top(); q.pop();
            p->next = tmp; p = p->next;
            tmp = tmp->next; if (tmp) q.push(tmp);
        }
        return root.next;
    }
};
