#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node
{
    TreeNode *root;
    bool visited;
    Node(TreeNode *tree) : root(tree), visited(false) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        stack<Node> stk;
        stk.push(Node(root));
        while (!stk.empty()) {
            Node tmp = stk.top(); stk.pop();
            if (tmp.visited) result.push_back(tmp.root->val);
            else {
                tmp.visited = true;
                stk.push(tmp);
                if (tmp.root->right) {
                    stk.push(Node(tmp.root->right));
                }
                if (tmp.root->left) {
                    stk.push(Node(tmp.root->left));
                }
            }
        }
        return result;
    }
};