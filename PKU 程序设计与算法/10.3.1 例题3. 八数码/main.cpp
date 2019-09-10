// poj 1077
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// up to 9!
const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int cantor(char a[], int n)
{
  int x = 0;
	for (int i = 0; i < n; ++i) {
		int smaller = 0;  // 在当前位之后小于其的个数
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[i])
				smaller++;
		}
		x += FAC[n - i - 1] * smaller; // 康托展开累加
	}
	return x;  // 康托展开值
}

struct Node {
  char matrix[9];
  int f;
  int idx;
  int zidx;
  char d;
};

bool visited[362880];
Node q[362880];

void printPath(int idx) {
  if (idx == 0) return;
  printPath(q[idx].f);
  cout<<q[idx].d;
}

int main(int argc, char const *argv[])
{
  char target[] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  int target_idx = cantor(target, 9);
  char tmpc;
  for (int i = 0; i < 9; ++i) {
    cin>>tmpc;
    if (tmpc == 'x') {q[0].matrix[i] = 0; q[0].zidx = i;}
    else q[0].matrix[i] = tmpc - '0';
  }
  q[0].idx = cantor(q[0].matrix, 9);
  visited[q[0].idx] = true;
  q[0].d = 0;
  q[0].f = -1;
  int front = 0;
  int rear = 1;
  while (front != rear) {
    Node &node = q[front++];
    // u
    if (node.zidx > 2)
    {
      Node &new_node = q[rear];
      memcpy(new_node.matrix, node.matrix, 9);
      swap(new_node.matrix[node.zidx], new_node.matrix[node.zidx-3]);
      new_node.idx = cantor(new_node.matrix, 9);
      if (!visited[new_node.idx]) {
        if (new_node.idx == target_idx) {
          printPath(front-1);
          cout<<"u";
          return 0;
        } 
        new_node.zidx = node.zidx-3;
        new_node.f = front-1;
        new_node.d = 'u';
        visited[new_node.idx] = true;
        rear++;
      }
    }
    
    // d
    if (node.zidx < 6)
    {
      Node &new_node = q[rear];
      memcpy(new_node.matrix, node.matrix, 9);
      swap(new_node.matrix[node.zidx], new_node.matrix[node.zidx+3]);
      new_node.idx = cantor(new_node.matrix, 9);
      if (!visited[new_node.idx]) {
        if (new_node.idx == target_idx) {
          printPath(front-1);
          cout<<"d";
          return 0;
        } 
        new_node.zidx = node.zidx+3;
        new_node.f = front-1;
        new_node.d = 'd';
        visited[new_node.idx] = true;
        rear++;
      }
    }
    // l
    if (node.zidx % 3 != 0)
    {
      Node &new_node = q[rear];
      memcpy(new_node.matrix, node.matrix, 9);
      swap(new_node.matrix[node.zidx], new_node.matrix[node.zidx-1]);
      new_node.idx = cantor(new_node.matrix, 9);
      if (!visited[new_node.idx]) {
        if (new_node.idx == target_idx) {
          printPath(front-1);
          cout<<"l";
          return 0;
        } 
        new_node.zidx = node.zidx-1;
        new_node.f = front-1;
        new_node.d = 'l';
        visited[new_node.idx] = true;
        rear++;
      }
    }
    // r
    if (node.zidx % 3 != 2)
    {
      Node &new_node = q[rear];
      memcpy(new_node.matrix, node.matrix, 9);
      swap(new_node.matrix[node.zidx], new_node.matrix[node.zidx+1]);
      new_node.idx = cantor(new_node.matrix, 9);
      if (!visited[new_node.idx]) {
        if (new_node.idx == target_idx) {
          printPath(front-1);
          cout<<"r";
          return 0;
        } 
        new_node.zidx = node.zidx+1;
        new_node.f = front-1;
        new_node.d = 'r';
        visited[new_node.idx] = true;
        rear++;
      }
    }
  }
  cout<<"unsolvable"<<endl;
  return 0;
}
