#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        for (ListNode* pn = root; pn; pn = pn->next) ++n;
        vector<ListNode*> res;
        int r = n % k;
        for (int i = 0; i < k; ++i) {
          ListNode* cur = nullptr, *pn = nullptr;
          if (i < r) {
            pn = cur = root;
            root = root->next;
            pn->next = nullptr;
          }
          for (int j = n/k; j; --j) {
            if (!cur) {
              pn = cur = root;
              root = root->next;
              pn->next = nullptr;
              continue;
            }
            pn->next = root;
            pn = pn->next;
            root = root->next;
            pn->next = nullptr;
          }
          res.push_back(cur);
        }
        return res;
    }
};
