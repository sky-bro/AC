#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const int mod = 1e9 + 7;

class Solution {
private:
    void update_tree_sums(TreeNode *root) {
        if (root->left) {
            update_tree_sums(root->left);
            root->val += root->left->val;
        }

        if (root->right) {
            update_tree_sums(root->right);
            root->val += root->right->val;
        }
    }
public:
    int maxProduct(TreeNode* root) {
        
        update_tree_sums(root);
        long long tree_sum = root->val, diff = tree_sum;
        long long sum_a, sum_b, result = 0;
        while (root) {
            sum_a = root->val;
            result = max(result, sum_a * (tree_sum - sum_a));
            if (root->left) {
                sum_a = root->left->val;
                result = max(result, sum_a * (tree_sum - sum_a));
                if (sum_a < tree_sum / 2) {
                    root = root->right;
                } else if (sum_a > tree_sum / 2) {
                    root = root->left;
                } else {
                    return sum_a * (tree_sum - sum_a) % mod;
                }
            } else if (root->right) {
                sum_a = root->right->val;
                result = max(result, sum_a * (tree_sum - sum_a));
                if (sum_a < tree_sum / 2) {
                    root = root->left;
                } else if (sum_a > tree_sum / 2) {
                    root = root->right;
                } else {
                    return result % mod;
                }
            } else break;

        }

        return result % mod;

    }
};

int main(int argc, char const *argv[])
{
    TreeNode a(1), b(2), c(3), d(4), e(5), f(6);
    // a.left = &b; a.right = &c;
    // b.left = &d; b.right = &e;
    // c.left = &f;
    a.right = &b;
    b.left = &c; b.right = &d;
    d.left = &e; d.right = &f;

    Solution s;
    cout<<s.maxProduct(&a)<<endl;
    return 0;
}
