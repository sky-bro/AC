#include <algorithm>
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
  vector<int> postorder(Node* root) {
    vector<int> res;
    if (!root) return res;
    stack<Node*> stk;
    stk.push(root);
    while (!stk.empty()) {
      Node* t = stk.top();
      stk.pop();
      res.push_back(t->val);
      for (auto it = t->children.begin(); it != t->children.end(); ++it) {
        stk.push(*it);
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};