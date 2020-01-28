#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<pair<TreeNode*, bool>> stk;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            stk.push(pair(root, false));
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        while (!stk.empty()) {
            auto &tmp = stk.top();
            if (tmp.second) {
                stk.pop();
                continue;
            }
            TreeNode *root = tmp.first->right;
            while (root) {
                stk.push(pair(root, false));
                root = root->left;
            }
            tmp.second = true;
            return tmp.first->val;
        }
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        while (!stk.empty()) {
            auto &tmp = stk.top();
            if (tmp.second) {
                stk.pop();
                continue;
            }
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */