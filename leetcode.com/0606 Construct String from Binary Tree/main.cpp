#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t)return "";
        string res = to_string(t->val);
        if (!t->left && !t->right) return res;
        else if (!t->right) {
          return res.append("("+tree2str(t->left)+")");
        } else {
          return res.append("("+tree2str(t->left)+")"+"("+tree2str(t->right)+")");
        }
    }
};