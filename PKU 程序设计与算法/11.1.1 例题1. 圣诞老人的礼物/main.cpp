// 百练4110
#include <cstdio>
#include <algorithm>

const double eps = 1e-6;

struct Box
{
  int v, w;
  bool operator < (Box &other) {
    return double(v)/double(w) - double(other.v)/double(other.w) < eps;
  }
};


int main(int argc, const char** argv) {
  int n, w;
  int v, w0;
  Box *boxes = new Box[n];
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; ++i) {
    Box b;
    scanf("%d%d", &b.v, &b.w);
    boxes[i] = b;
  }
  std::sort(boxes, boxes+n);
  double sum = 0;
  for (int i = n-1; i >= 0 && w > 0; --i) {
    if (boxes[i].w <= w) {
      sum += boxes[i].v;
      w -= boxes[i].w;
    } else {
      sum += boxes[i].v*(double(w)/boxes[i].w);
      w=0;
    }
  }
  printf("%.1f\n", sum);
  delete [] boxes;
  return 0;
}