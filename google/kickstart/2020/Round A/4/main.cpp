#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int cnt;  // how many words reach here
  unordered_map<char, Node *> children;
  Node(int _cnt) : cnt(_cnt) {}
  ~Node() {
    for (auto &p : children) {
      delete p.second;
      p.second = nullptr;  // ? do I need this
    }
  }
};

/**
 * @param word the word to be added to the trie
 * @returns true if this word is new, false if not
 */
bool add_word(Node *proot, char *word) {
  proot->cnt++;
  Node *pn = proot;
  for (; *word; ++word) {
    char c = *word;
    auto nxt = pn->children.find(c);
    if (nxt == pn->children.end()) {
      Node *tmp_node = new Node(1);
      pn->children.emplace(c, tmp_node);
      pn = tmp_node;
    } else {
      pn = nxt->second;
      pn->cnt++;
    }
  }
  return pn->cnt == 1;
}

char word[2000001];

void solve(int case_num) {
  int N, K;
  scanf("%d%d", &N, &K);
  Node root(0);
  for (int i = 0; i < N; ++i) {
    scanf("%s", word);
    // printf("add word: %s\n", word);
    add_word(&root, word);
  }

  int res = 0;
  stack<Node *> stk;
  stk.push(&root);
  while (!stk.empty()) {
    Node *pn = stk.top();
    stk.pop();
    for (auto &p : pn->children) {
      if (p.second->cnt >= K) {
        stk.push(p.second);
        res += p.second->cnt / K;
      }
    }
  }

  printf("Case #%d: %d\n", case_num, res);
}

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  return 0;
}
