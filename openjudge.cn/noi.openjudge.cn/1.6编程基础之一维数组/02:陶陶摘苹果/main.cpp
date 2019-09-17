#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
  int a[10], h, cnt=10;
  for (int i = 0; i < 10; ++i) {
    cin>>a[i];
  }
  cin>>h;
  h+=30;
  for (int i = 0; i < 10; ++i) {
    if (a[i] > h) --cnt;
  }
  cout<<cnt<<endl;
  return 0;
}