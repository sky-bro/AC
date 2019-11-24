#include <iostream>
#include <stack>

using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// 递归
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) return true;
        if (p == nullptr && q != nullptr || p != nullptr && q == nullptr) return false;
        else return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// 非递归
class Solution2 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        stk1.push(p);
        stk2.push(q);
        while (!stk1.empty()) {
            TreeNode *cur1 = stk1.top(); stk1.pop();
            TreeNode *cur2 = stk2.top(); stk2.pop();
            if (cur1 == cur2) continue;
            if (cur1 == nullptr && cur2 || cur2 == nullptr && cur1) return false;
            if (cur1->val != cur2->val) {
                return false;
            }
            stk1.push(cur1->left); stk2.push(cur2->left);
            stk1.push(cur1->right); stk2.push(cur2->right);
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    TreeNode *root2 = new TreeNode(10);
    root2->left = new TreeNode(5);
    root2->left->left = nullptr;
    root2->left->right = new TreeNode(15);
    root2->right = nullptr;

    // Solution s;
    Solution2 s;
    cout<<s.isSameTree(root, root2)<<endl;
    delete root->left;
    delete root->right;
    delete root;
    delete root2->left->right;
    delete root2->left;
    delete root2;
    return 0;
}
