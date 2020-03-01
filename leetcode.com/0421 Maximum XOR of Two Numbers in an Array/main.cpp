#include <iostream>
#include <vector>

using namespace std;

#undef TreeNode

struct Tree {
  Tree* left;
  Tree* right;
  Tree(Tree* l, Tree* r) : left(l), right(r) {}
  Tree() : left(nullptr), right(nullptr) {}
  //   ~Tree() {
  //     if (left) delete left;
  //     if (right) delete right;
  //   }
  bool find(int num, int prefix_len) {
    Tree* pnode = this;
    for (int i = 30; i >= 31 - prefix_len; --i) {
      if ((num >> i) & 1) {
        if (pnode->left) {
          pnode = pnode->left;
        } else {
          return false;
        }
      } else {
        if (pnode->right) {
          pnode = pnode->right;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

// ref:
// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/184434/JavaTrie99
class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int res = 0;
    Tree tree;
    for (int num : nums) {
      Tree* pnode = &tree;
      for (int i = 30; i >= 0; --i) {
        if ((num >> i) & 1) {
          if (pnode->left == nullptr) {
            pnode->left = new Tree();
          }
          pnode = pnode->left;
        } else {
          if (pnode->right == nullptr) {
            pnode->right = new Tree();
          }
          pnode = pnode->right;
        }
      }
    }
    for (int prefix_len = 1; prefix_len <= 31; ++prefix_len) {
      res = res << 1;
      for (int num : nums) {
        num ^= (res + 1) << (31 - prefix_len);
        if (tree.find(num, prefix_len)) {
          ++res;
          break;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {3, 10, 5, 25, 2, 8};
  cout << s.findMaximumXOR(nums) << endl;
  return 0;
}
