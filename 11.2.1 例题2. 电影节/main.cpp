#include <cstdio>
#include <algorithm>

struct Film
{
  int b, e;
  bool operator < (Film & other) {
    return e < other.e;
  }
};

int main(int argc, const char** argv) {
  int n;
  while (true) {
    scanf("%d", &n);
    if (n == 0) break;
    Film *films = new Film[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &films[i].b, &films[i].e);
    }
    std::sort(films, films+n);
    int prev_e = -1;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      if (films[i].b < prev_e) continue;
      prev_e = films[i].e;
      result++;
    }
    printf("%d\n", result);
    delete [] films;
  }
  return 0;
}