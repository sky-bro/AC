// famer有限制坐标在0～NAXN吗
#include <iostream>
#include <queue>

using namespace std;

int N, K;
const int MAXN = 100000;
int visited[MAXN+10];

struct Step {
  int x;
  int steps;
  Step(int xx, int s):x(xx),steps(s){}
};

int bfs(int farmer, int cow) {
  queue<Step> q;
  q.push(Step(farmer, 0));
  visited[farmer] = 1;
  while (!q.empty())
  {
    Step cur = q.front();q.pop();
    
    if (cur.x == cow) return cur.steps;

    if (cur.x - 1 >= 0 && !visited[cur.x - 1]) {
      q.push(Step(cur.x - 1, cur.steps + 1));
      visited[cur.x - 1] = 1;
    }
    if (cur.x + 1 <= MAXN && !visited[cur.x + 1]) {
      q.push(Step(cur.x + 1, cur.steps + 1));
      visited[cur.x + 1] = 1;
    } 
    if (cur.x * 2 <= MAXN && !visited[cur.x * 2]) {
      q.push(Step(cur.x * 2, cur.steps + 1));
      visited[cur.x * 2] = 1;
    } 
  }
  return -1;
}

int main(int argc, char const *argv[])
{
  cin>>N>>K;
  cout<<bfs(N, K)<<endl;
  return 0;
}


