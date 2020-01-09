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
    int result;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left_sum = dfs(root->left);
        int right_sum = dfs(root->right);
        int tmp_result = root->val + left_sum + right_sum;
        if (tmp_result > result) result = tmp_result;
        tmp_result = root->val + max(left_sum, right_sum);
        if (tmp_result <= 0) return 0;
        else return tmp_result;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        result = root->val;
        dfs(root);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode left(2);
    TreeNode right(3);
    TreeNode root(1);
    root.left = &left;
    root.right = &right;
    
    Solution s;
    cout<<s.maxPathSum(&root)<<endl;
    return 0;
}
