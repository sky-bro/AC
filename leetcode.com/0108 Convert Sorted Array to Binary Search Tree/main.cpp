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
    TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right) {
        int mid = left + (right - left + 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (mid - left) root->left = _sortedArrayToBST(nums, left, mid-1);
        if (right - mid) root->right = _sortedArrayToBST(nums, mid+1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return nullptr;
        return _sortedArrayToBST(nums, 0, n-1);
    }
};