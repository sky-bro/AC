#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
  string name;
  vector<Node *> children;
  Node(string name) { this->name = name; }
  Node() {}
  ~Node() {
    for (Node *child : children) delete child;
  }
};

class ThroneInheritance {
 private:
  unordered_set<string> dead;
  Node *root;
  unordered_map<string, Node *> name2Node;

 public:
  ThroneInheritance(string kingName) {
    root = new Node(kingName);
    name2Node.emplace(kingName, root);
  }

  ~ThroneInheritance() { delete root; }

  void birth(string parentName, string childName) {
    Node *pnode = name2Node[parentName];
    pnode->children.push_back(new Node(childName));
    name2Node.emplace(childName, pnode->children.back());
  }

  void death(string name) { dead.insert(name); }

  void dfs(vector<string> &res, Node *pnode) {
    if (!dead.count(pnode->name)) res.push_back(pnode->name);
    for (auto &child : pnode->children) {
      dfs(res, child);
    }
  }
  vector<string> getInheritanceOrder() {
    vector<string> res;
    dfs(res, root);
    return res;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  // ["ThroneInheritance","birth","birth","birth","birth","birth","birth","getInheritanceOrder","death","getInheritanceOrder"]
  // [["king"],["king","andy"],["king","bob"],["king","catherine"],["andy","matthew"],["bob","alex"],["bob","asha"],[null],["bob"],[null]]
  ThroneInheritance th("king");
  th.birth("king", "andy");
  th.birth("king", "bob");
  th.birth("king", "catherine");
  th.birth("andy", "matthew");
  th.birth("bob", "alex");
  th.birth("bob", "asha");
  printArr(th.getInheritanceOrder());
  th.death("bob");
  printArr(th.getInheritanceOrder());
  return 0;
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
