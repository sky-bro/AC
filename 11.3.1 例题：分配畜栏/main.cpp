// poj 3190
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct Cow {
  int start, end;
  int cow_id;
  bool operator < (const Cow &other) const{
    return start < other.start;
  }
};

struct Stall {
  int stall_id;
  int end;
  Stall(int id, int e): stall_id(id), end(e){}
  bool operator < (const Stall &other) const {
    return end > other.end;
  }
};

int N;
int cow_stall[50000]; // result
Cow cows[50000];
priority_queue<Stall> pq;

int next_id = 1;

int main(int argc, char const *argv[])
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d%d", &cows[i].start, &cows[i].end);
    cows[i].cow_id = i;
  }
  sort(cows, cows + N);
  pq.push(Stall(next_id++, cows[0].end));
  cow_stall[cows[0].cow_id] = 1;
  for (int i = 1; i < N; ++i) {
    Stall st = pq.top();
    if (cows[i].start > st.end) {
      pq.pop();
      pq.push(Stall(st.stall_id, cows[i].end));
      cow_stall[cows[i].cow_id] = st.stall_id;
    } else {
      pq.push(Stall(next_id++, cows[i].end));
      cow_stall[cows[i].cow_id] = next_id-1;
    }
  }
  printf("%d\n", next_id-1);
  for (int i = 0; i < N; ++i) {
    printf("%d\n", cow_stall[i]);
  }
  return 0;
}
