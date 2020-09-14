#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// idea: count tails of connected components

// ref:
// https://leetcode.com/problems/linked-list-components/discuss/123842/C%2B%2BJavaPython-Easy-and-Concise-Solution-with-Explanation

class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& G) {
    unordered_set<int> g(G.begin(), G.end());
    int res = 0;
    while (head) {
      if (g.count(head->val) &&
          (head->next == nullptr || !g.count(head->next->val)))
        ++res;
      head = head->next;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  ListNode a(1), b(3, &a), c(4, &b), d(2, &c), e(0, &d);
  vector<int> G = {3, 2, 4};
  Solution s;
  cout << s.numComponents(&e, G) << endl;
  return 0;
}
