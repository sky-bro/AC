#include <iostream>

using namespace std;

int blks[50][50];
int colors[50][50];
int roomNum;
int maxArea, area;

void dfs(int r, int c) {
  if (colors[r][c] != 0) return;
  colors[r][c] = roomNum; area++;
  if ((blks[r][c] & 1) == 0) dfs(r, c-1);
  if ((blks[r][c] & 2) == 0) dfs(r-1, c);
  if ((blks[r][c] & 4) == 0) dfs(r, c+1);
  if ((blks[r][c] & 8) == 0) dfs(r+1, c);
}

int main(int argc, char const *argv[])
{
  int R, C;
  cin>>R>>C;
  for (int i = 0; i < R; ++i){
    for (int j = 0; j < C; ++j) {
      cin>>blks[i][j];
    }
  }
  for (int i = 0; i < R; ++i){
    for (int j = 0; j < C; ++j) {
      if (colors[i][j] == 0) {
        roomNum++;
        area = 0;
        dfs(i, j);
        if (area > maxArea) maxArea = area;
      }
    }
  }
  cout<<roomNum<<endl;
  cout<<maxArea<<endl;
  return 0;
}
