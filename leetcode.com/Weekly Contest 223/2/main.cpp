#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *swapNodes(ListNode *head, int k) {
    vector<ListNode *> stk;
    auto p = head;
    while (p) {
      stk.push_back(p);
      p = p->next;
    }
    auto p1 = stk[k - 1];
    auto p2 = stk[stk.size() - k];
    swap(p1->val, p2->val);
    return head;
  }
};
