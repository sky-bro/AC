#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* pn = q.front(); q.pop();
            if (pn->left) q.push(pn->left);
            if (pn->right) q.push(pn->right);
            for (int i = 1; i < n; ++i) {
                pn->next = q.front(); q.pop();
                pn = pn->next;
                if (pn->left) q.push(pn->left);
                if (pn->right) q.push(pn->right);
            }
            pn->next = nullptr;
        }
        return root;
    }
};
