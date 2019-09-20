#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  int L, M, a, b, sum=0;
  cin>>L>>M;
  int *arr = new int[L+1];
  for (int i = 0; i <= L; ++i) arr[i]=1;
  for (int i = 0; i < M; ++i) {
    cin>>a>>b;
    for (int j = a; j <= b; ++j) {
      arr[j] = 0;
    }
  }
  for (int i = 0; i <= L; ++i) sum+=arr[i];
  cout<<sum<<endl;
  return 0;
}