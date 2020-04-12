#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> words = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
vector<int> word_lens;
char arr[] = {'"', '\'', '&', '>', '<', '/'};

struct Node {
  int idx;
  unordered_map<char, Node*> children;
  Node() : idx(-1) {}
};

void delete_trees(Node* root){
  if (!root) return;
  for (auto p: root->children) {
    delete_trees(p.second);
  }
  delete root;
}

class Solution {
 private:
  Node* root;
  int search(const string& s, int cur) {
    Node* pnode = root;
    while (true) {
      if (pnode->idx != -1) return pnode->idx;
      auto it = pnode->children.find(s[cur++]);
      if (it == pnode->children.end()) {
        return -1;
      }
      pnode = it->second;
    }
    return -1;
  }

 public:
  Solution() {
    root = new Node();
    for (int i = 0; i < 6; ++i) {
      string word = words[i];
      Node* pnode = root;
      for (char c : word) {
        auto it = pnode->children.find(c);
        if (it != pnode->children.end()) {
          pnode = it->second;
        } else {
          Node* next_node = new Node();
          pnode->children.emplace(c, next_node);
          pnode = next_node;
        }
      }
      pnode->idx = i;
    }
    for (string& word : words) {
      word_lens.push_back(word.length());
    }
  }
  ~Solution() {
    delete_trees(root);
  }
  string entityParser(string text) {
    string res = "";
    int n = text.length();
    for (int i = 0; i < n;) {
      int idx = search(text, i);
      if (idx == -1) {
        res.push_back(text[i++]);
      } else {
        res.push_back(arr[idx]);
        i += word_lens[idx];
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string text = "&amp; is an HTML entity but &ambassador; is not.";
  cout << s.entityParser(text) << endl;
  return 0;
}
