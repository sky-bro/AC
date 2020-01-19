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
		int lengthA = length(headA), lengthB = length(headB);
		ListNode *p = headA, *q = headB;
		if (lengthA > lengthB)
			return getIntersectionNode(p, lengthA, q, lengthB);
		else
			return getIntersectionNode(q, lengthB, p, lengthA);
	}

	int length(ListNode* head){
		ListNode* p = head;
		int length = 0;
		while (p != NULL){
			length++;
			p = p->next;
		}
		return length;
	}

	ListNode *getIntersectionNode(ListNode *p, int length1, ListNode *q, int length2){
		while (length1 != length2)
		{
			p = p->next;
			length1--;
		}
		while (p){
			if (p != q){
				p = p->next;
				q = q->next;
			}
			else
				return p;
		}
        return nullptr;
	}
};