#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
  int dfs(Node* root) {
    if (root->children.empty()) return 1;
    int res = 0;
    for (Node* n : root->children) res = max(res, dfs(n));
    // for_each(root->children.begin(), root->children.end(),
    //          [&](Node* n) { res = max(res, dfs(n)); });
    return res + 1;
  }

 public:
  int maxDepth(Node* root) {
    if (!root) return 0;
    return dfs(root);
  }
};