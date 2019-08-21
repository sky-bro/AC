#include <iostream>
#include <queue>

using namespace std;

int M, N, T;

struct Node
{
  int x, y;
  int s;
  int t;
  Node(int xx, int yy, int tt, int ss):x(xx), y(yy), t(tt), s(ss){}
};

queue<Node> q;

bool matrix[200][200];
int energy_took[200][200];

int bfs(int startX, int startY, int endX, int endY) {
  Node start(startX, startY, 0, 0);
  energy_took[startX][startY] = 0;
  int x_diff[4] = {-1, 1, 0, 0};
  int y_diff[4] = {0, 0, -1, 1};
  q.push(start);
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int x = node.x + x_diff[i];
      int y = node.y + y_diff[i];
      if (x >= 0 && x < M && y >=0 && y < N ){
        int t = node.t + matrix[x][y];
        if (energy_took[x][y] > t && t <= T) {
          if (x == endX && y == endY) return node.s+1;
          q.push(Node(x, y, t, node.s+1));
          energy_took[x][y] = t;
        }
      }
    }
  }
  return -1;
}

int main(int argc, char const *argv[])
{
  cin>>M>>N>>T;
  int mingrenX, mingrenY, zuozhuX, zuozhuY;
  char tmp;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin>>tmp; matrix[i][j] = false; energy_took[i][j] = T+1;
      if (tmp == '@') {mingrenX = i; mingrenY = j;}
      else if (tmp == '#') {matrix[i][j]=true;}
      else if (tmp == '+')  {zuozhuX = i; zuozhuY = j;}
    }
  }
  cout<<bfs(mingrenX, mingrenY, zuozhuX, zuozhuY)<<endl;
  return 0;
}
