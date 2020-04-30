#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int reachNumber(int target) {
    if (target == 0)
      return 0;
    else if (target < 0)
      target = -target;

    int n = int((sqrt(target*8LL+1LL)-1)/2);
    int len = (1 + n) * n / 2;
    return len == target ? n : ((len - target + n + 1)&1 ? n + (n&1 ? 2 : 3) : n + 1) ;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  int target;
  while (cin>>target) {
    cout<<s.reachNumber(target)<<endl;
  }
  return 0;
}
