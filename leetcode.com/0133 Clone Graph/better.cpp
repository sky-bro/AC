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

// simpler, but slower? recursive
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr; 
        if(m.count(node))
            return m[node];
        Node *cloneNode = new Node(node->val, vector<Node*>());
        m[node] = cloneNode;
        for(auto neighbor : node->neighbors){
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        return cloneNode;
    }
private:
    unordered_map<Node*, Node*> m;
};
