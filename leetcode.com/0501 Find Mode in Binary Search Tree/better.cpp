#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历 == 从小到大遍历
class Solution {
private:
    vector<int> result;
    int pre_val=-1, cnt = 0, max_cnt = 0;
    void _findMode(TreeNode* root) {
        if (!root) return;
        _findMode(root->left);
        
        cnt = root->val == pre_val ? cnt+1 : 1;

        if (max_cnt < cnt) {
            max_cnt = cnt;
            result.clear();
            result.push_back(root->val);
        } else if (max_cnt == cnt) {
            result.push_back(root->val);
        }

        pre_val = root->val;
        _findMode(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        _findMode(root);
        return result;
    }

    void print() {
        for (auto i: result) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    void reset() {
        pre_val = -1;
        cnt = max_cnt = 0;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode tn1(1), tn2(2), tn3(2);
    tn1.right = &tn2;
    tn2.left = &tn3;
    Solution s;
    s.findMode(&tn1);
    s.print();
    s.reset();
    return 0;
}