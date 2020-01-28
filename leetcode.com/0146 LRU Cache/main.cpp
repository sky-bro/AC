#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class LRUCache {
private:
    struct Node
    {
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int _key, int _val, Node *_next, Node *_prev): key(_key), val(_val), next(_next), prev(_prev){}
    };
    
    int _capacity;
    int _size;
    unordered_map<int, Node*> keys;
    Node* head; // most recently used
    Node* tail; // least recently used

    void update_list(Node *pnode) {
        if (pnode == head) return;
        pnode->prev->next = pnode->next;
        if (pnode == tail) {
            tail = pnode->prev;
        } else {
            pnode->next->prev = pnode->prev;
        }
        pnode->prev = nullptr;
        pnode->next = head;
        head->prev = pnode;
        head = pnode;
    }
public:
    LRUCache(int capacity): _capacity(capacity), _size(0), head(nullptr), tail(nullptr) {
        if (capacity <= 0) _capacity = 1;
    }
    
    int get(int key) {
        if (keys.count(key) == 0) return -1;
        Node *pnode = keys[key];
        update_list(pnode);
        return head->val;
    }
    
    void put(int key, int value) {
        Node *pnode = nullptr;
        if (keys.count(key)) {
            Node *pnode = keys[key];
            update_list(pnode);
            pnode->val = value;
            return;
        }
        
        if (_size < _capacity) {
            ++_size;
            keys[key] = head = new Node(key, value, head, nullptr);
            if (_size == 1) tail = head;
            if (head->next) head->next->prev = head;
            return;
        }

        keys.erase(tail->key);
        keys[key] = tail;
        tail->key = key;
        tail->val = value;
        update_list(tail);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */