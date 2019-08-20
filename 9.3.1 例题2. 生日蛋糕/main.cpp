#include <iostream>
#include <cmath>

using namespace std;

// 蛋糕体积N * pi, M层
int N, M;

int minArea, area;

int min_area(int m) {
  // 2pi*r*h
  // 2*1*1 + 2* 2*2+2*3*3+...+2*m*m
  // 立方和公式: n*(n+1)*(2*n+1)/6
  return m*(m+1)*(2*m+1)/3;
}

// int max_area(int m, int r, int h) {
//   int ret = 0;
//   for (int i = 0; i < m; ++m, --r, --h) {
//     ret += 2*r*h;
//   }
//   return ret;
// }

int min_volume(int m) {
  // pi*r*r*h
  // 1^3 + 2^3 + ... + m^3
  // 立方和公式: (n(n+1)/2)^2
  int tmp = (m*(m+1)/2);
  return tmp * tmp;
}

int max_volume(int m, int r, int h) {
  int ret = 0;
  for (int i = 0; i < m; ++i, --r, --h) {
    ret += r*r*h;
  }
  return ret;
}

void dfs(int v, int m, int r, int h){
  if (v < 0) return;
  if (m==0) {
    if (v) return;
    minArea = min(area, minArea); return;
  }

  if (min_area(m) + area >= minArea || 
    min_volume(m) > v)
    return;

  for (int rr = r; rr >= m; --rr) {
    if (m == M) area = rr*rr;
    for (int hh = h; hh >= m; --hh) {
      if (max_volume(m, rr, hh) < v) continue;
      area += 2*rr*hh;
      dfs(v-rr*rr*hh, m-1, rr-1, hh-1);
      area -= 2*rr*hh;
    }
  }
}

int main(int argc, char const *argv[])
{
  cin>>N>>M;
  minArea = 1 << 30;
  int r = floor(sqrt(N));
  int h = N;
  dfs(N, M, r, h);
  if (minArea == 1 << 30) cout<<0<<endl;
  else cout<<minArea<<endl;
  return 0;
}
