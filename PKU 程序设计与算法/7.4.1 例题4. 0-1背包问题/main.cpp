#include <iostream>

using namespace std;

int w[3410]; // weights
int d[3410]; // desirabilities
int v[12881]; // greatest sums (values)

inline int max (int a, int b) {
  return a>b?a:b;
}

int main(int argc, char const *argv[])
{
  int N, M;
  cin>>N>>M;
  // v[n][m] = max { v[n-1][m], v[n-1][m-w[n]] + d[n] }
  for (int i = 1; i <= N; ++i)
  {
    cin>>w[i]>>d[i];
  }

  for (int i = 1; i <= N; ++i)
  {
    for (int j = M; j >= 1; --j)
    {
      if (j - w[i] >= 0)
        v[j] = max(v[j], v[j-w[i]] + d[i]);      
    }
  }
  cout << v[M] << endl;
  return 0;
}
 