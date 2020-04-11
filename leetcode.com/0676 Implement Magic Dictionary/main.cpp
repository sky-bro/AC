#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  bool isWord;
  unordered_map<char, Node*> children;
  Node(bool _isWord = false) : isWord(_isWord) {}
};

class MagicDictionary {
 private:
  Node* root;
  void delete_tree(Node* root) {
    for (auto& p : root->children) {
      delete_tree(p.second);
    }
    delete root;
  }

 public:
  /** Initialize your data structure here. */
  MagicDictionary() { root = new Node(); }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    for (const string& word : dict) {
      Node* pnode = root;
      for (char c : word) {
        auto it = pnode->children.find(c);
        if (it == pnode->children.end()) {
          Node* next_node = new Node();
          pnode->children.emplace(c, next_node);
          pnode = next_node;
        } else {
          pnode = it->second;
        }
      }
      pnode->isWord = true;
    }
  }

  bool dfs(const string& word, int i, int n, Node* cur, bool modified) {
    if (i == n) {
      return modified && cur->isWord;
    }
    if (modified) {
      auto it = cur->children.find(word[i]);
      if (it == cur->children.end()) return false;
      return dfs(word, i + 1, n, it->second, true);
    }
    for (auto& p : cur->children) {
      if (p.first == word[i]) {
        if (dfs(word, i + 1, n, p.second, false)) return true;
      } else {
        if (dfs(word, i + 1, n, p.second, true)) return true;
      }
    }
    return false;
  }
  /** Returns if there is any word in the trie that equals to the given word
   * after modifying exactly one character */
  bool search(string word) { return dfs(word, 0, word.length(), root, false); }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */