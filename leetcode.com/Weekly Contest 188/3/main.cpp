#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int cnt, res;
  bool dfs(vector<vector<int>> &G, vector<bool>& hasApple, int i) {
    bool flag = false;
    if (hasApple[i]) {
      flag = true;
      --cnt;
      if (cnt == 0) return flag;
    }
    for (int child: G[i]) {
      if (dfs(G, hasApple, child)) {res += 2; flag = true;}
      if (cnt == 0) return flag;
    }
    return flag;
  }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        cnt = 0;
        res = 0;
        for (bool b: hasApple) if (b) ++cnt;
        vector<vector<int>> G(n);
        for (auto &edge: edges) {
          G[edge[0]].push_back(edge[1]);
        }
        if (cnt == 0) return 0;
        dfs(G, hasApple, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  int n = 7;
  vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
  vector<bool> hasApple = {false,false,true,false,true,true,false};
  cout<<s.minTime(n, edges, hasApple)<<endl;
  return 0;
}
