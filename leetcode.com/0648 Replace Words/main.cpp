#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int idx;  // -1 means not a word
  unordered_map<char, Node*> children;
  Node(int _idx = -1) : idx(_idx) {}
};

class Trie {
 private:
  Node* root;
  void delete_tree(Node* root) {
    for (auto it = root->children.begin(); it != root->children.end(); ++it) {
      delete_tree(it->second);
    }
    delete root;
  }

 public:
  Trie(vector<string> words) {
    root = new Node();
    for (int i = words.size() - 1; i >= 0; --i) {
      Node* pnode = root;
      for (char c : words[i]) {
        if (!pnode->children.count(c)) {
          pnode->children.emplace(c, new Node());
        }
        pnode = pnode->children[c];
      }
      pnode->idx = i;
    }
  }

  ~Trie() { delete_tree(root); }

  int search(const string& word) {
    Node* pnode = root;
    for (char c : word) {
      if (!pnode->children.count(c)) break;
      pnode = pnode->children[c];
      if (pnode->idx != -1) return pnode->idx;
    }
    return -1;
  }
};

class Solution {
 public:
  string replaceWords(vector<string>& dict, string sentence) {
    Trie t(dict);
    istringstream ISS(sentence);
    string word;
    ISS >> word;
    int idx = t.search(word);
    string res = ~idx ? dict[idx] : word;
    while (ISS >> word) {
      idx = t.search(word);
      res.push_back(' ');
      res += ~idx ? dict[idx] : word;
    }
    return res;
  }
};
