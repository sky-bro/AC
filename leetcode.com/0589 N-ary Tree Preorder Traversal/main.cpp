#include <iostream>
#include <stack>
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
  vector<int> preorder(Node* root) {
    stack<Node*> stk;
    vector<int> res;
    if (!root) return res;
    stk.push(root);
    while (!stk.empty()) {
      Node* t = stk.top();
      stk.pop();
      res.push_back(t->val);
      for (auto it = t->children.rbegin(); it != t->children.rend(); ++it) {
        stk.push(*it);
      }
    }
    return res;
  }
};