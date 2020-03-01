#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  char c;
  vector<int> rank;
  bool operator<(const Node& b) const {
    const Node& a = *this;
    int n = a.rank.size();
    for (int i = 0; i < n; ++i) {
      if (a.rank[i] != b.rank[i]) return a.rank[i] > b.rank[i];
    }
    return a.c < b.c;
  }
  Node(char cc, int n) : c(cc) { rank.resize(n); }
  Node() {}
};

class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    int n = votes[0].length();
    unordered_map<char, Node> mp;
    vector<Node> vn;
    for (int i = 0; i < n; ++i) {
      mp[votes[0][i]] = Node(votes[0][i], n);
    }
    for (string& vote : votes) {
      for (int i = 0; i < n; ++i) {
        mp[vote[i]].rank[i]++;
      }
    }
    string res = "";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      vn.push_back(it->second);
    }
    sort(vn.begin(), vn.end());
    for (Node& node : vn) {
      res.push_back(node.c);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> vs = {"ABC", "ACB", "ABC", "ACB", "ACB"};
  cout << s.rankTeams(vs) << endl;
  return 0;
}
