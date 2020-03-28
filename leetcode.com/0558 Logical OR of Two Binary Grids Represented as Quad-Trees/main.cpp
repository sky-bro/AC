#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

Node* copy_node(Node* n0) {
  if (n0->isLeaf) return new Node(n0->val, 1);
  return new Node(n0->val, 0, copy_node(n0->topLeft), copy_node(n0->topRight),
                  copy_node(n0->bottomLeft), copy_node(n0->bottomRight));
}

class Solution {
 private:
  Node* dfs(Node* t1, Node* t2) {
    if (t1->isLeaf && t2->isLeaf) {
      return new Node(t1->val | t2->val, 1);
    }
    Node *nt1 = 0, *nt2 = 0, *nt3 = 0, *nt4 = 0;
    if (t1->isLeaf) {
      if (t1->val)
        return new Node(1, 1);
      else
        return copy_node(t2);
    } else if (t2->isLeaf) {
      if (t2->val)
        return new Node(1, 1);
      else
        return copy_node(t1);
    } else {
      nt1 = dfs(t1->topLeft, t2->topLeft);
      nt2 = dfs(t1->topRight, t2->topRight);
      nt3 = dfs(t1->bottomLeft, t2->bottomLeft);
      nt4 = dfs(t1->bottomRight, t2->bottomRight);
    }
    if (nt1->isLeaf && nt2->isLeaf && nt3->isLeaf && nt4->isLeaf &&
        nt1->val == nt2->val && nt1->val == nt3->val && nt1->val == nt4->val) {
      delete nt2;
      delete nt3;
      delete nt4;
      return nt1;
    }
    return new Node(0, 0, nt1, nt2, nt3, nt4);
  }

 public:
  Node* intersect(Node* quadTree1, Node* quadTree2) {
    return dfs(quadTree1, quadTree2);
  }
};