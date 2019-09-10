// POJ 3984
#include <iostream>

using namespace std;

struct Node {
  int x, y;
  int f;
  Node(int xx, int yy, int ff): x(xx), y(yy), f(ff){}
  Node(){}
};

int maze[5][5];
int visited[5][5];
Node q[25];
int front;
int back;

void printPath(Node & node) {
  if (node.f == -1) {
    cout<<"("<<node.x<<", "<<node.y<<")"<<endl;
    return;
  }
  printPath(q[node.f]);
  cout<<"("<<node.x<<", "<<node.y<<")"<<endl;
}

void bfs(int startx, int starty, int endx, int endy) {
  front = back = 0;
  q[back++] = Node(0 ,0, -1);
  while (front != back) {
    Node node = q[front++];
    if (node.x == endx && node.y == endy) {
      printPath(node);
      return;
    } 
    if (node.x - 1 >= 0 && !maze[node.x-1][node.y] &&!visited[node.x-1][node.y]) {
      q[back++] = Node(node.x-1 ,node.y, front-1);
      visited[node.x-1][node.y] = 1;
    }
    if (node.x + 1 <= 4 && !maze[node.x+1][node.y] &&!visited[node.x+1][node.y]) {
      q[back++] = Node(node.x+1 ,node.y, front-1);
      visited[node.x+1][node.y] = 1;
    }
    if (node.y - 1 >= 0 && !maze[node.x][node.y-1] &&!visited[node.x][node.y-1]) {
      q[back++] = Node(node.x ,node.y-1, front-1);
      visited[node.x][node.y-1] = 1;
    }
    if (node.y + 1 <= 4 && !maze[node.x][node.y+1] &&!visited[node.x][node.y+1]) {
      q[back++] = Node(node.x ,node.y+1, front-1);
      visited[node.x][node.y+1] = 1;
    }
  }
}

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      cin>>maze[i][j];
  bfs(0, 0, 4, 4);
  return 0;
}
