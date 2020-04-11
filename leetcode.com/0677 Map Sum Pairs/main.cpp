#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int sum;
  unordered_map<char, Node*> children;
  Node(int _sum) : sum(_sum) {}
};

// use map + trie
class MapSum {
 private:
  Node* root;
  unordered_map<string, int> m;
  void delete_tree(Node* root) {
    if (!root) return;
    for (auto& p : root->children) {
      delete_tree(p.second);
    }
    delete root;
  }

 public:
  /** Initialize your data structure here. */
  MapSum() {
    root = new Node(0);
    m.clear();
  }

  ~MapSum() { delete_tree(root); }

  void insert(string key, int val) {
    Node* pnode = root;
    auto it = m.find(key);
    if (it != m.end()) {
      int bak = val;
      val -= it->second;
      it->second = bak;
    } else {
        m.emplace(key, val);
    }
    pnode->sum += val;
    for (char c : key) {
        auto it  = pnode->children.find(c);
        if (it == pnode->children.end()) {
            Node *next_node = new Node(val);
            pnode->children.emplace(c, next_node);
            pnode = next_node;
        } else {
            pnode = it->second;
            pnode->sum += val;
        }
    }
  }

  int sum(string prefix) {
      Node* pnode = root;
      for (char c: prefix) {
          auto it = pnode->children.find(c);
          if (it == pnode->children.end()) return 0;
          pnode = it->second;
      }
      return pnode->sum;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(int argc, char const *argv[])
{
    MapSum ms;
    ms.insert("appple", 3);
    ms.insert("appple", 4);
    cout<<ms.sum("ap")<<endl;
    ms.insert("app", 2);
    cout<<ms.sum("ap")<<endl;
    return 0;
}
