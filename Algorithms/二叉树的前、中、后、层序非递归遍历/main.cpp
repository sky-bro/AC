// refs:
// https://blog.csdn.net/billy1900/article/details/86229656
// https://blog.csdn.net/qq_35812205/article/details/96476519
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorder_traversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode *pnode = stk.top(); stk.pop();
        result.push_back(pnode->val);
        // push right then push left
        if (pnode->right) stk.push(pnode->right);
        if (pnode->left) stk.push(pnode->left);
    }
    return result;
}

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

vector<int> postorder_traversal(TreeNode* root) {
    vector<int> result;

    return result;
}

vector<int> levelorder_traversal(TreeNode* root) {
    vector<int> result;

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
    TreeNode root(1), left(0), right(2);
    root.left = &left; root.right = &right;

    print_arr(preorder_traversal(&root));
    print_arr(inorder_traversal(&root));
    // print_arr(postorder_traversal(&root));
    // print_arr(levelorder_traversal(&root));

    return 0;
}
