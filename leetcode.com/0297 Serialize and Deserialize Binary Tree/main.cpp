#include <iostream>
#include <vector>
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
private:
    char ourDel = ' ';
    void serializeNode(TreeNode* root, ostringstream& OSS) {
        if (!root) {
            OSS<<"#"<<ourDel;
            return;
        }
        OSS << root->val << ourDel;
        serializeNode(root->left, OSS);
        serializeNode(root->right, OSS);
    }

    TreeNode* deserializeNode(istringstream& ISS) {
        string nodeValue;
        ISS>>nodeValue;
        if (nodeValue == "#") {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(stoi(nodeValue));
        newNode->left = deserializeNode(ISS);
        newNode->right = deserializeNode(ISS);
        return newNode;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream OSS;
        serializeNode(root, OSS);
        return OSS.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ISS(data);
        return deserializeNode(ISS);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));