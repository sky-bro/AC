#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  unordered_map<char, Node *> children;
  ~Node() {
    for (auto p : children) {
      delete p.second;
      p.second = nullptr;
    }
  }
};

// trie

class Solution {
 private:
  Node *root = nullptr;
  /**
   * add word to the root (trie)
   * @param word word (suffix) to be added to this suffix tree
   * @returns true if this is a new suffix, or false if not
   */
  bool add_word(const string &word) {
    bool is_new_suffix = false;
    auto p = root;
    for (int i = word.size() - 1; i >= 0; --i) {
      char c = word[i];
      auto it = p->children.find(c);
      if (it == p->children.end()) {
        is_new_suffix = true;
        auto np = new Node;
        p->children.emplace(c, np);
        p = np;
      } else {
        p = it->second;
      }
    }
    return is_new_suffix;
  }

 public:
  int minimumLengthEncoding(vector<string> &words) {
    root = new Node;
    sort(words.begin(), words.end(),
         [](const string &a, const string &b) { return a.size() > b.size(); });
    int len = 0;
    for (const string &word : words) {
      if (add_word(word)) {
        len += word.length() + 1;
      }
    }
    delete root;
    root = nullptr;
    return len;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<string> words = {"time", "me", "bell"};
  cout << s.minimumLengthEncoding(words) << endl;
  return 0;
}
