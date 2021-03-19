#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    bool is_word;
    unordered_map<char, Node*> children;
    Node(): is_word(false) {}
};

class Trie
{ 
private:
    Node *root;
    /**
     * @returns true if pnode has no children, so pnode will be deleted after return
     * return false if pnode still has children after deleting word[idx] (this prefix is still in use by other words)
     */
    bool _delete_word(const string &word, int idx, Node *pnode) {
        if (idx == word.length()) {
            pnode->is_word = false;
            if (pnode->children.empty()) return true;
            return false;
        }
        if (pnode->children.count(word[idx])) {
            Node *pnode_child = pnode->children[word[idx]];
            if (_delete_word(word, idx+1, pnode_child)) {
                delete pnode_child;
                pnode->children.erase(word[idx]);
                if (pnode->children.empty()) return true;
            }
        }
        return false;
    }

    void delete_tree(Node *root) {
        if (!root) return;
        for (auto it = root->children.begin(); it != root->children.end(); ++it) {
            delete_tree(it->second);
        }
        delete root;
    }
public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        delete_tree(root);
    }
    void insert(string word) {
        Node *pnode = root;
        for (char c: word) {
            if (!pnode->children.count(c)) {
                pnode->children[c] = new Node();
            }
            pnode = pnode->children[c];
        }
        pnode->is_word = true;
    }

    Node* search_prefix(string prefix) {
        Node *pnode = root;
        for (char c: prefix) {
            if (!pnode->children.count(c)) {
                return nullptr;
            }
            pnode = pnode->children[c];
        }
        return pnode;
    }

    bool search(string word) {
        Node *pnode = search_prefix(word);
        if (pnode) return pnode->is_word;
        return false;
    }

    void delete_word(string word) {
        _delete_word(word, 0, root);
    }
};

int main(int argc, char const *argv[])
{
    Trie trie;
    trie.insert("abcd");
    trie.insert("abcef");
    cout << trie.search_prefix("abc")->is_word << endl;
    trie.delete_word("abc");
    trie.delete_word("abcd");
    cout << trie.search_prefix("abc")->is_word << endl;
    cout << trie.search_prefix("abcd") << endl;
    cout << trie.search_prefix("abce")->is_word << endl;
    cout << trie.search_prefix("abcef")->is_word << endl;
    return 0;
}

