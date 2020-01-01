// https://www.jianshu.com/p/2b49eb904806
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution {
private:
    struct Node
    {
        TreeNode *tree;
        bool visited;
        Node(TreeNode *_tree): tree(_tree), visited(false){}
    };
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node> stk;
        stk.push(Node(root));
        while (!stk.empty()) {
            Node tmp = stk.top(); stk.pop();
            if (tmp.visited) {
                result.push_back(tmp.tree->val);
            } else {
                tmp.visited = true;
                if (tmp.tree->right) stk.push(Node(tmp.tree->right));
                stk.push(tmp);
                if (tmp.tree->left) stk.push(Node(tmp.tree->left));
            }
        }
        return result;
    }
};
