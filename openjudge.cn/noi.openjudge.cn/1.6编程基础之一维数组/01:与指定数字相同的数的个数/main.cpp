#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  int n, m, cnt=0;
  cin>>n;
  int *a = new int[n];
  for (int i = 0; i < n; ++i) {
    cin>>a[i];
  }
  cin>>m;
  for (int i = 0; i < n; ++i) {
    if (a[i] == m) ++cnt;
  }
  cout<<cnt<<endl;
  delete [] a;
  return 0;
}