// 百练1328 http://bailian.openjudge.cn/practice/1328

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double EPS = 1e-6;

struct Island {
  double left, right;
  bool operator < (const Island & other) const {
    return left - other.left < -EPS;
  }
};

Island islands[1000];

int main(int argc, char const *argv[])
{
  int n, r;
  int x, y;
  int caseN = 1;
  int result = -1;
  bool solved = false;
  while (true) {
    cin>>n>>r;
    if (n == 0) break;
    solved = false;
    result = -1;
    for (int i = 0; i < n; ++i) {
      cin>>x>>y;
      if (y > r || solved) {
        solved = true;
        continue;
      }
      double diff = sqrt(r*r*1.0-y*y);
      islands[i].left = x-diff;
      islands[i].right = x+diff;
    }
    if (solved) {
      cout<<"Case "<< caseN++ <<": -1" <<endl;
      continue;
    }
    sort(islands, islands+n);
    result = 1;
    double tmpRight = islands[0].right;
    for (int i = 1; i < n; ++i) {
      if (islands[i].left - tmpRight > EPS) {
        result++;
        tmpRight = islands[i].right;
      } else {
        tmpRight = min(islands[i].right, tmpRight);
      }
    }
    cout<<"Case "<< caseN++ <<": "<< result <<endl;
  }
  return 0;
}
