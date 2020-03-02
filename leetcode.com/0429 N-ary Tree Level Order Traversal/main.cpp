#include <iostream>
#include <queue>
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
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> level;
      for (int sz = q.size(); sz > 0; --sz) {
        Node* pnode = q.front();
        q.pop();
        level.push_back(pnode->val);
        for (Node* child : pnode->children) {
          q.push(child);
        }
      }
      res.emplace_back(level);
    }
    return res;
  }
};