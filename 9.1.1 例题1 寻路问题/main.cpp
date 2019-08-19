/*
5
6
7
1 2 2 3
2 4 3 3
3 4 2 4
1 3 4 1
4 6 2 1
3 5 2 0
5 4 3 2
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int minLen;
int totalLen;
int totalCost;
int K,N,R;
int visited[110];

struct Road {
  int d,L,t;
};

vector< vector< Road > > G(110);
// minL[i][j]
int minL[110][10010];

void dfs(int s) {
  if (s == N) {
    if (totalLen < minLen) minLen = totalLen;
    return;
  }
  for (int i = 0; i < G[s].size(); ++i) {
    Road r = G[s][i];
    if (!visited[r.d] && totalCost + r.t < K && minLen < totalLen + r.L) {
      if (totalLen + r.L >= minL[r.d][totalCost + r.t]) continue;
      minL[r.d][totalCost+r.t] = totalLen + r.L;
      totalLen += r.L;
      totalCost += r.t;
      visited[r.d] = 1;
      dfs(r.d);
      visited[r.d] = 0;
      totalLen -= r.L;
      totalCost -= r.t;
    }
  }
}

int main(int argc, char const *argv[])
{
  cin>>K>>N>>R;
  for (int i = 0; i < R; ++i){
    int s;
    Road r;
    cin>>s>>r.d>>r.L>>r.t;
    if (s!=r.d){
      G[s].push_back(r);
    }
  }
  memset(visited, 0, sizeof(visited));
  totalLen = 0;
  minLen = 1 << 30;
  totalCost = 0;
  visited[1] = 1;
  for (int i = 0; i < 110; ++i)
    for (int j = 0; j < 10010; ++j)
      minL[i][j] = 1 << 30;
  dfs(1);
  if (minLen < 1 << 30) cout<< minLen <<endl;
  else cout<<-1<<endl;
  return 0;
}
