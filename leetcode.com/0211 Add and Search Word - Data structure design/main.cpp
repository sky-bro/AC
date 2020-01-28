#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    bool isWord;
    unordered_map<char, Node*> children;
    Node(): isWord(false) {}
};


class WordDictionary {
private:
    Node* root;
    bool search_helper(const string &word, int idx, Node *root) {
        if (idx == word.length()) {
            if (root->isWord) return true;
            return false;
        }
        if (word[idx] != '.') {
            if (!root->children.count(word[idx])) return false;
            return search_helper(word, idx+1, root->children[word[idx]]);
        }
        for (auto it = root->children.begin(); it != root->children.end(); ++it) {
            if (search_helper(word, idx+1, it->second)) return true;
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *pnode = root;
        for (char c: word) {
            if (!pnode->children.count(c)) {
                pnode->children[c] = new Node();
            }
            pnode = pnode->children[c];
        }
        pnode->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_helper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */