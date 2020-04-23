#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <numeric>

#include "leetcode.hpp"

using namespace std;

class Solution {
private:
  int n;
  vector<int> id;
  unordered_map<string, int> email2id;
  int Find(int x) {
    while (x != id[x]) x = id[x];
    return x;
  }

  void Union(int p, int q) {
    int pID = Find(p), qID = Find(q);
    if (pID == qID) return;
    id[qID] = pID;
  }
  
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      n = accounts.size();
      id.clear();
      id.resize(n);
      iota(id.begin(), id.end(), 0);
      for (int i = 0; i < n; ++i) {
        for (int j = accounts[i].size()-1; j >0; --j) {
          auto it = email2id.find(accounts[i][j]);
          if (it != email2id.end()) {
            Union(it->second, i);
          } else {
            email2id.emplace(accounts[i][j], i);
          }
        }
      }

      unordered_map<int, set<string>> res0;
      for (int i = 0; i < n; ++i) {
        int cur_id = Find(i);
        res0[cur_id].insert(accounts[i].begin()+1, accounts[i].end());
      }
      vector<vector<string>> res;
      for (auto &p: res0) {
        vector<string> row;
        row.push_back(accounts[p.first][0]);
        row.insert(row.end(), p.second.begin(), p.second.end());
        res.push_back(row);
      }
      return res;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
  printArr2D(s.accountsMerge(accounts));
  return 0;
}
