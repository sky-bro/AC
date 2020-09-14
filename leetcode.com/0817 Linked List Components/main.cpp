#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  unordered_map<int, int> num2id;
  vector<int> ids;
  int n, res;
  int F(int x) {
    int r = x;
    while (r != ids[r]) r = ids[r];

    while (x != r) {
      int nx = ids[x];
      ids[x] = r;
      x = nx;
    }

    return r;
  }
  void U(int p, int q) {
    // not in G
    if (num2id.end() == num2id.find(p) || num2id.end() == num2id.find(q))
      return;
    p = F(num2id[p]), q = F(num2id[q]);
    if (p != q) {
      --res;
      ids[q] = p;
    }
  }

 public:
  int numComponents(ListNode* head, vector<int>& G) {
    n = res = G.size();
    ids.clear();
    num2id.clear();
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < n; ++i) {
      num2id.emplace(G[i], i);
    }
    int pre = head->val;
    head = head->next;
    while (head) {
      U(pre, head->val);
      pre = head->val;
      head = head->next;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  ListNode a(1), b(3, &a), c(4, &b), d(2, &c), e(0, &d);
  vector<int> G = {3, 2, 4};
  Solution s;
  cout << s.numComponents(&e, G) << endl;
  return 0;
}
