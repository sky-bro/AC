// 百练 4103:踩方格
#include <iostream>

using namespace std;

int visited[30][50];

int ways(int r, int c, int n){
  if (n == 0) return 1;
  int num = 0;
  visited[r][c] = 1;
  if (!visited[r][c-1]) num += ways(r, c-1, n-1);
  if (!visited[r][c+1]) num += ways(r, c+1, n-1);
  if (!visited[r+1][c]) num += ways(r+1, c, n-1);
  visited[r][c] = 0;
  return num;
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  cout<<ways(0, 25, n)<<endl;
  return 0;
}
