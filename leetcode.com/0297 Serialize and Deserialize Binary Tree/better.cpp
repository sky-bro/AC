#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ref: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/430572/C%2B%2B-Beats-95-Advanced-String-Stream-Technique-(with-Video-Explanation!)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;  
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(!q.empty()) {
            TreeNode *node=q.front();q.pop();
            if(node) {
                os<<node->val<<" ";
                q.push(node->left);q.push(node->right);
            }
            else os<<"#"<<" ";
        }//while
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size()) return NULL;
        istringstream is(data);
        string s;is>>s;
        queue<TreeNode*> q;
        TreeNode *root=new TreeNode(stoi(s));
        q.push(root);
        while(!q.empty()) {
            TreeNode *node=q.front();q.pop();
            if(!node) {continue;}
            is>>s;
            if(s!="#") {
                node->left=new TreeNode(stoi(s));
            }
            else node->left=NULL;
            q.push(node->left);
            is>>s;
            if(s!="#") {
                node->right=new TreeNode(stoi(s));
            }
            else node->right=NULL;
            q.push(node->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));