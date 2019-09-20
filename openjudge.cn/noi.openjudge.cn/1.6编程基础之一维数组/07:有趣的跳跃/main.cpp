#include <iostream>
using namespace std;
int a[3000];

int main(int argc, const char** argv) {
  int n, prev, cur, ind;
  cin>>n>>prev;
  for (int i = 1; i < n; ++i) {
    cin>>cur;
    ind = prev > cur? prev-cur:cur-prev;
    prev = cur;
    if (ind >= n || ind == 0) {
      ind = 0;
    }
    a[ind]++;
  }
  if (n != 1) {
    for (int i = 1; i < n; ++i) {
      if (a[i] != 1) {
        cout<<"Not jolly"<<endl;
        return 0;
      }
    }
  }
  cout<<"Jolly"<<endl;
  return 0;
}