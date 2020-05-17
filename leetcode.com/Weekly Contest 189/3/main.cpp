#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int id = 0, n = favoriteCompanies.size();
        unordered_map<string, int> ids;
        vector<bitset<50001>> bucket;
        for (int i = 0; i < n; ++i) {
          auto &favs = favoriteCompanies[i];
          bitset<50001> cur;
          for (const string &fav: favs) {
            auto it = ids.find(fav);
            if (it == ids.end()) ids.emplace(fav, id++);
            cur[ids[fav]] = 1;
          }
          bucket.push_back(cur);
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
          int j = 0;
          for (; j < n; ++j) {
            if (i == j) continue;
            auto t = bucket[i] & bucket[j];
            if (t == bucket[i]) break;
          }
          if (j == n) res.push_back(i);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<vector<string>> favs = {{"leetcode","google","facebook"},{"leetcode","amazon"},{"facebook","google"}};
  s.peopleIndexes(favs);
  return 0;
}

