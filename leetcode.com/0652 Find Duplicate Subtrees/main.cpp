#include <iostream>
#include <unordered_map>
#include <map>
#include <tuple>
#include <vector>

#include "leetcode.hpp"

using namespace std;

typedef tuple<int, int, int> TreeType;

// #### THIS is essentially a tree hashing problem #####
// or even more essentially: given left subtree's hash & right subtree's hash & cur_root value, compute hash of current tree

// ref: No string hash, Python code, O(n) time and space
// https://leetcode.com/problems/find-duplicate-subtrees/discuss/106022/No-string-hash-Python-code-O(n)-time-and-space
// 44ms
class Solution {
 private:
  int next_id;
  map<TreeType, pair<int, bool>> type2id_dup;
  vector<TreeNode*> res;
  int dfs(TreeNode* root) {
    if (!root) return -1;
    TreeType cur_type(root->val, dfs(root->left), dfs(root->right));
    auto it = type2id_dup.find(cur_type);
    int cur_id;
    if (it != type2id_dup.end()) {
      cur_id = it->second.first;
      if (it->second.second == false) {
        it->second.second = true;
        res.push_back(root);
      }
    } else {
      cur_id = next_id++;
      type2id_dup.emplace(cur_type, make_pair(cur_id, false));
    }
    return cur_id;
  }

 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    next_id = 0;
    type2id_dup.clear();
    res.clear();
    dfs(root);
    return res;
  }
};

// need to define a hash function for TreeType (tuple)
// check README or the include/ folder, see how to hash tuples
// 20ms
// this is essentially a tree hashing problem: tree -> treetype -> id (give each type an id/hash)
// see better.cpp: directly from tree to id (hash of the tree)
// typedef tuple<int, int, int> TreeType;
class Solution {
 private:
  int next_id;
  unordered_map<TreeType, pair<int, bool>, hash<TreeType>> type2id_dup;
  vector<TreeNode*> res;
  int dfs(TreeNode* root) {
    if (!root) return -1;
    TreeType cur_type(root->val, dfs(root->left), dfs(root->right));
    auto it = type2id_dup.find(cur_type);
    int cur_id;
    if (it != type2id_dup.end()) {
      cur_id = it->second.first;
      if (it->second.second == false) {
        it->second.second = true;
        res.push_back(root);
      }
    } else {
      cur_id = next_id++;
      type2id_dup.emplace(cur_type, make_pair(cur_id, false));
    }
    return cur_id;
  }

 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    next_id = 0;
    type2id_dup.clear();
    res.clear();
    dfs(root);
    return res;
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
