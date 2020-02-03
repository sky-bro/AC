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
    vector<string> result;
    void helper(TreeNode* root, vector<int> &path) {
        path.push_back(root->val);
        if (root->left) helper(root->left, path);
        if (root->right) helper(root->right, path);
        if (!root->left && !root->right) {
            string path_str = to_string(path[0]);
            for (int i = 1; i < path.size(); ++i) {
                path_str += "->"+to_string(path[i]);
            }
            result.push_back(path_str);
        }
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<int> path;
        helper(root, path);
        return result;
    }
};