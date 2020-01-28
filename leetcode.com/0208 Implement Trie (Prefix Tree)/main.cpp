#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    bool isWord;
    unordered_map<char, Node*> children;
    Node(): isWord(false) {}
};


class Trie {
private:
    Node* root = nullptr;
    void delete_tree(Node *root) {
        for (auto it = root->children.begin(); it != root->children.end(); ) {
            delete_tree(it->second);
            root->children.erase(it++);
        }
        delete root;
    }
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *pnode = root;
        for (char c: word) {
            if (!pnode->children.count(c)) {
                pnode->children[c] = new Node();
            }
            pnode = pnode->children[c];
        }
        pnode->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *pnode = root;
        for (char c: word) {
            if (!pnode->children.count(c)) return false;
            pnode = pnode->children[c];
        }
        if (pnode->isWord) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *pnode = root;
        for (char c: prefix) {
            if (!pnode->children.count(c)) return false;
            pnode = pnode->children[c];
        }
        return true;
    }

    ~Trie() {
        delete_tree(root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */