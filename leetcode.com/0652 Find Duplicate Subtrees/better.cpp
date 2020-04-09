#include <array>
#include <iostream>
#include <unordered_map>

#include "leetcode.hpp"

using namespace std;

// from fastest (12ms) solution
// post: C++ 15ms (< 99.76%) 
// https://leetcode.com/problems/find-duplicate-subtrees/discuss/112442/C%2B%2B-15ms-(less-99.76)

class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<long, pair<int,int>> counts;    
    vector<TreeNode*> ans;
    getId(root, counts, ans);
    return ans;
  }
private:
  int getId(TreeNode* root, 
            unordered_map<long, pair<int,int>>& counts,
            vector<TreeNode*>& ans) {
    if (!root) return 0;
    long key = (static_cast<long>(static_cast<unsigned>(root->val)) << 32) +
               (getId(root->left, counts, ans) << 16) +
                getId(root->right, counts, ans);    
    auto& p = counts[key];
    if (p.second++ == 0)
      p.first = counts.size();    
    else if (p.second == 2)
      ans.push_back(root);
    return p.first;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    TreeNode* root = stringToTreeNode(str);
    vector<TreeNode*> res = s.findDuplicateSubtrees(root);
    for (TreeNode* node : res) {
      cout << node->val << " ";
    }
    cout << endl;
    delete_tree(root);
  }
  return 0;
}
