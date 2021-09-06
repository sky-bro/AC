// refs:
// https://blog.csdn.net/billy1900/article/details/86229656
// https://blog.csdn.net/qq_35812205/article/details/96476519
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// leetcode 144. Binary Tree Preorder Traversal
vector<int> preorder_traversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    if (root) stk.push(root);
    while (!stk.empty()) {
        TreeNode *pnode = stk.top(); stk.pop();
        result.push_back(pnode->val);
        // push right then push left
        if (pnode->right) stk.push(pnode->right);
        if (pnode->left) stk.push(pnode->left);
    }
    return result;
}

// leetcode 94. Binary Tree Inorder Traversal
vector<int> inorder_traversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    while (!stk.empty() || root) {
        if (root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top(); stk.pop();
            result.push_back(root->val);
            root = root->right;
        }
    }
    return result;
}

// leetcode 145. Binary Tree Postorder Traversal
vector<int> postorder_traversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    TreeNode *pre = nullptr;
    do {
        while (root) {
            stk.push(root);
            root = root->left;
        }
        
        TreeNode *pre = nullptr;
        while (!stk.empty()) {
            root = stk.top();
            if (root->right == pre) {
                result.push_back(root->val);
                stk.pop();
                pre = root;
            } else {
                root = root->right;
                break;
            }
        }
    } while (!stk.empty());
    return result;
}

vector<vector<int>> levelorder_traversal(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        vector<int> row;
        for (int sz = q.size(); sz; --sz) {
            TreeNode *p = q.front(); q.pop();
            row.push_back(p->val);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        result.push_back(row);
    }
    return result;
}

void print_arr(const vector<int> &vals) {
    for (int val: vals) {
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    TreeNode root(1), left(2), right(3);
    // root.left = &left; root.right = &right;
    root.right = &left;
    left.left = &right;

    print_arr(preorder_traversal(&root));
    print_arr(inorder_traversal(&root));
    print_arr(postorder_traversal(&root));
    // print_arr(levelorder_traversal(&root));

    return 0;
}
