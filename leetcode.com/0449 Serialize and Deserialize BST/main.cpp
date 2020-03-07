#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) return "";
    ostringstream OSS;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *pnode = stk.top();
      stk.pop();
      OSS << pnode->val << " ";
      if (pnode->right) stk.push(pnode->right);
      if (pnode->left) stk.push(pnode->left);
    }
    return OSS.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data == "") return nullptr;
    istringstream ISS(data);
    string s;
    stack<TreeNode *> stk;
    ISS >> s;
    TreeNode *root = new TreeNode(stoi(s));
    stk.push(root);
    while (ISS >> s) {
      int num = stoi(s);
      TreeNode *pnode = stk.top(), *pfather = nullptr;
      stk.pop();
      if (!stk.empty()) pfather = stk.top();

      while (pfather && (pfather->val < pnode->val != pfather->val < num)) {
        pnode = pfather;
        stk.pop();
        if (stk.empty())
          pfather = nullptr;
        else
          pfather = stk.top();
      }

      if (num < pnode->val) {
        pnode->left = new TreeNode(num);
        stk.push(pnode);  // right hand not visited
        stk.push(pnode->left);
      } else {
        pnode->right = new TreeNode(num);
        stk.push(pnode->right);
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char const *argv[]) {
  Codec codec;
  TreeNode root(2);
  TreeNode left(1);
  TreeNode right(3);
  root.left = &left;
  root.right = &right;

  string data = codec.serialize(&root);
  cout << data << endl;
  codec.deserialize(data);
  return 0;
}
