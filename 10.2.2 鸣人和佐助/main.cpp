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

char matrix[200][200];
bool visited[200][200];

int bfs(int startX, int startY) {
  Node start(startX, startY, 0, 0);
  visited[startX][startY] = true;
  q.push(start);
  while (!q.empty()) {
    Node node = q.front(); q.pop();

    if (node.x - 1 >= 0 && !visited[node.x-1][node.y]) {
      switch (matrix[node.x-1][node.y])
      {
      case '*':
        q.push(Node(node.x-1, node.y, node.t, node.s+1));
        visited[node.x-1][node.y] = true;
        break;
      case '#':
        if (node.t + 1 <= T) {
          q.push(Node(node.x-1, node.y, node.t+1, node.s+1));
          visited[node.x-1][node.y] = true;
        }
        break;
      case '+':
        return node.s + 1;
        break;
      }
    }
    if (node.x + 1 < M && !visited[node.x+1][node.y]) {
      switch (matrix[node.x+1][node.y])
      {
      case '*':
        q.push(Node(node.x+1, node.y, node.t, node.s+1));
        visited[node.x+1][node.y] = true;
        break;
      case '#':
        if (node.t + 1 <= T) {
          q.push(Node(node.x+1, node.y, node.t+1, node.s+1));
          visited[node.x+1][node.y] = true;
        }
        break;
      case '+':
        return node.s + 1;
        break;
      }
    }
    if (node.y - 1 >= 0 && !visited[node.x][node.y-1]) {
      switch (matrix[node.x][node.y-1])
      {
      case '*':
        q.push(Node(node.x, node.y-1, node.t, node.s+1));
        visited[node.x][node.y-1] = true;
        break;
      case '#':
        if (node.t + 1 <= T) {
          q.push(Node(node.x, node.y-1, node.t+1, node.s+1));
          visited[node.x][node.y-1] = true;
        }
        break;
      case '+':
        return node.s + 1;
        break;
      }
    }
    if (node.y + 1 < N && !visited[node.x][node.y+1]) {
      switch (matrix[node.x][node.y+1])
      {
      case '*':
        q.push(Node(node.x, node.y+1, node.t, node.s+1));
        visited[node.x][node.y+1] = true;
        break;
      case '#':
        if (node.t + 1 <= T) {
          q.push(Node(node.x, node.y+1, node.t+1, node.s+1));
          visited[node.x][node.y+1] = true;
        }
        break;
      case '+':
        return node.s + 1;
        break;
      }
    }
  }
  return -1;
}

int main(int argc, char const *argv[])
{
  cin>>M>>N>>T;
  int mingrenX, mingrenY, zuozhuX, zuozhuY;
  // char tmp;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin>>matrix[i][j];
      if (matrix[i][j] == '@') {
        mingrenX = i;
        mingrenY = j;
      }
    }
  }
  cout<<bfs(mingrenX, mingrenY)<<endl;
  return 0;
}
