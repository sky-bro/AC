#include <iostream>
#include <vector>
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
    // return true, delete child
    // return false, no more delete, always return false later
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

    void delete_tree(Node *pnode) {
        if (!pnode) return;
        for (auto it = pnode->children.begin(); it != pnode->children.end(); ++it) {
            delete_tree(it->second);
        }
        delete pnode;
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

    Node* move(Node* from, char c) {
        if (!from) from = root;
        if (from->children.count(c)) {
            return from->children[c];
        } else return nullptr;
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

class Solution {
private:
    vector<string> found_words;
    Trie trie;
    int m, n;
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, string &word) {
        word.push_back(board[i][j]);
        
        Node *pnode = trie.search_prefix(word);
        if (!pnode) {
            word.pop_back();
            return;
        }

        visited[i][j] = true;

        // find a word
        if (pnode->is_word) {
            trie.delete_word(word);
            found_words.push_back(word);
        }

        if (i < m - 1 && !visited[i+1][j]) {
            dfs(board, i+1, j, visited, word);
        }

        if (i > 0 && !visited[i-1][j]) {
            dfs(board, i-1, j, visited, word);
        }

        if (j < n - 1 && !visited[i][j+1]) {
            dfs(board, i, j+1, visited, word);
        }

        if (j > 0 && !visited[i][j-1]) {
            dfs(board, i, j-1, visited, word);
        }

        word.pop_back();
        visited[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        for (string &word: words) {
            trie.insert(word);
        }
        vector<vector<bool>> visited(m, vector<bool>(n));
        string word = "";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, visited, word);
            }
        }
        return found_words;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    s.findWords(board, words);
    return 0;
}
