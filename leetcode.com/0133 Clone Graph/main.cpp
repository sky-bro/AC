// DFS, use stack
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // stk0放原图的节点
        // stk1放新图的节点
        stack<Node *> stk0, stk1;
        unordered_map<int, Node*> m;
        Node *root = new Node(node->val, vector<Node*>()), *tmp, *ori_node, *new_node;
        stk0.push(node);
        stk1.push(root);
        m[node->val] = root;
        while (!stk0.empty()) {
            ori_node = stk0.top(); stk0.pop();
            new_node = stk1.top(); stk1.pop();
            for (auto pn: ori_node->neighbors) {
                if (m.find(pn->val) == m.end()) {
                    tmp = new Node(pn->val, vector<Node*>());
                    m[pn->val] = tmp;
                    stk0.push(pn); stk1.push(tmp);
                }
                new_node->neighbors.push_back(m[pn->val]);
            }
        }
        return root;
    }
};
