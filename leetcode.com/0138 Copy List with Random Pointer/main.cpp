#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> m;
        Node* new_head = new Node(head->val);
        Node* result = new_head;

        m[head] = new_head;
        m[nullptr] = nullptr;

        for (; head; head = head->next, new_head = new_head->next) {
            if (!m.count(head->random)) {
                m[head->random] = new Node(head->random->val);
            }
            new_head->random = m[head->random];

            if (!m.count(head->next)) {
                m[head->next] = new Node(head->next->val);
            }
            new_head->next = m[head->next];
        }
        return result;
    }
};