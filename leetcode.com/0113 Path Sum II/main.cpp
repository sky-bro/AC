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
    vector<vector<int>> result;
    int sum;
    void _pathSum(TreeNode* root, vector<int> &path) {
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == 0) result.push_back(path);
        } else {
            if (root->left) _pathSum(root->left, path);
            if (root->right) _pathSum(root->right, path);
        }
        sum += root->val;
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        if (!root) return result;
        vector<int> path;
        this->sum = sum;
        _pathSum(root, path);
        return result;
    }
};