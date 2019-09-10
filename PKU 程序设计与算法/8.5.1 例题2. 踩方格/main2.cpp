// 百练 4103:踩方格
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  int a = 1, b = 3, tmp;
  if (n == 0) {
    cout << a << endl;
    return 0;
  }
  for (int i = 1; i < n; ++i){
    tmp = b;
    b = 2*b+a;
    a = tmp;
  }
  cout<<b<<endl;
  return 0;
}
