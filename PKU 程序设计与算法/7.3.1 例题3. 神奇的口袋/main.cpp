// 可以用滚动数组
#include <iostream>

using namespace std;

int N;
int ways[21][41];
int weights[21];

int main(){
  cin>>N;
  for (int i = 1; i <= N; ++i){
    cin>>weights[i];
  }
  for (int i = 0; i <= N; ++i) ways[i][0] = 1;
  for (int i = 1; i <= N; ++i){
    int weight = weights[i];
    for (int j = 1; j <= 40; ++j){
      ways[i][j] = ways[i-1][j];
      if (j - weight >= 0)
        ways[i][j] += ways[i-1][j-weight];
    }
  }
  cout<<ways[N][40]<<endl;
  return 0;
}