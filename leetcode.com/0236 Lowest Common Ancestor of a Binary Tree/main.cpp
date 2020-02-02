#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *result, *p, *q; // if result != null, we've found our LCA
    bool _helper(TreeNode *root) {
        if (result) return false;
        int found_cnt = 0;
        if (root == p) ++found_cnt; // found p
        if (root == q) ++found_cnt; // use if, instead of else if, in case: p == q
        // if we have found_cnt = 2, root is our LCA
        // if found_cnt = 2, no need to traverse another sub tree
        if (found_cnt !=2 && root->left) if (_helper(root->left)) ++found_cnt;
        if (found_cnt !=2 && root->right) if (_helper(root->right)) ++found_cnt;
        // we may have found our LCA in the above sub routines, return then
        if (result) return false;
        // for the first time, we have found_cnt = 2, root is our LCA
        if (found_cnt == 2) {
            result = root;
            return false;
        }
        // found_cnt could be 1: means we have found one of p, q; or we have found LCA in the sub routines
        // found_cnt could be 0: means we have found none of p, q
        return found_cnt;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // don't know if below four cases are legal
        if (!root) return nullptr; // case 1: root == null, return null
        if (p) {
            if (!q) return p; // case 2: p != null && q == null, return p
        } else if (q) {
            return q; // case 3: p == null && q != null, return q
        } else {
            while (root->left) root = root->left;
            return root; // case 4: p == null && q == null, return the left most node (silly...)
        }

        // root != nullptr && p != nullptr && q != nullptr
        result = nullptr; // haven't found LCA yet
        this->p = p; this->q = q;
        _helper(root);
        return result;
    }
};