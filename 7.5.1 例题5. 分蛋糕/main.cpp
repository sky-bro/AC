/**
 * 有一块矩形大蛋糕，长和宽分别是整数w、h。现要将其切成m块小蛋糕，每个小蛋糕都必须是矩形、且宽和高均为整数。切蛋糕时，每次切一块蛋糕，将其分成两个矩形蛋糕。请计算：最后得到的m块小蛋糕中，最大的那块蛋糕的面积下限。
 * http://noi.openjudge.cn/ch0405/6047/
 * */
#include <iostream>
#include <algorithm>

using namespace std;

int v[21][21][21];

int main(int argc, char const *argv[])
{
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= 20; j++)
    {
      int K = i * j;
      for (int k = 1; k <= K && k <= 20; k++)
      {
        v[i][j][k] = K;
        if (k == 1) continue;

        int vtmp;
        // 竖着切
        for (int w = 1; w <= i / 2; ++w) {
          for (int kk = 1; kk < k; ++kk) {
            vtmp = max(v[w][j][kk], v[i-w][j][k-kk]);
            if (vtmp < v[i][j][k]) v[i][j][k] = vtmp;
          }
        }
        // 横着切
        for (int h = 1; h <= j / 2; ++h) {
          for (int kk = 1; kk < k; ++kk) {
            vtmp = max(v[i][h][kk], v[i][j-h][k-kk]);
            if (vtmp < v[i][j][k]) v[i][j][k] = vtmp;
          }          
        }
      }
      
    }
    
  }
  int w, h, m;
  cin>>w>>h>>m;
  while (w != 0) {
    cout<<v[w][h][m]<<endl;
    cin>>w>>h>>m;
  }
  return 0;
}
