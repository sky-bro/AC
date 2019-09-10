// 百练 1042
#include <iostream>
#include <queue>

using namespace std;



int n, t;
int fi[25];
int di[25];
int dis[24];
int Max, CurMax;
int result[25];
int tmp_result[25];
int * fish[25];

struct Slice {
  int lake_id;
  int slice_idx;
  Slice(int lake, int slice): lake_id(lake), slice_idx(slice) {}
  bool operator < (const Slice & other) const {
    if (fish[lake_id][slice_idx] != fish[other.lake_id][other.slice_idx]) {
      return fish[lake_id][slice_idx] < fish[other.lake_id][other.slice_idx];
    } else {
      return lake_id > other.lake_id;
    }
  }
};

int main(int argc, char const *argv[])
{
  while (cin>>n && n) {
    cin>>t; t *= 12; // number of time intervals
    for (int i = 0; i < n; ++i) cin>>fi[i];
    for (int i = 0; i < n; ++i) cin>>di[i];
    for (int i = 0; i < n-1; ++i) cin>>dis[i];
    for (int i = 0; i < n; ++i) {
      result[i] = 0;
      fish[i] = new int[t+1]; // ind can reach to t(why? the last pq.push), so t+1 for size
      for (int j=0; j < t; ++j) {
        fish[i][j] = fi[i] - j*di[i];
        if (fish[i][j] < 0) fish[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      int tt = t;
      for (int j = 0; j < i-1; ++j) {
        tt -= dis[j];
      }
      // 如果因走路耗光时间 肯定不是解(后面也会更多走路时间 直接break) 就在第一个lake钓鱼不需要走路
      if (tt < 0) break;
      // choose best time slices
      priority_queue<Slice> pq;
      for (int j = 0; j < i; ++j) {
        pq.push(Slice(j, 0));
        tmp_result[j] = 0; // initiate result arr to all 0s
      }
      CurMax = 0;
      for (int j = 0; j < tt; ++j) {
        Slice tmp_slice = pq.top();
        CurMax += fish[tmp_slice.lake_id][tmp_slice.slice_idx];
        // add 1 time slice to the lake with id: lake_id
        tmp_result[tmp_slice.lake_id]+=5;
        pq.pop();
        pq.push(Slice(tmp_slice.lake_id, tmp_slice.slice_idx+1));
      }
      if (CurMax > Max || i == 1) {
        for (int j = 0; j < i; ++j) {
          result[j] = tmp_result[j];
        }
        Max = CurMax;
      }
    }
    for (int i = 0; i < n; ++i) {
      delete [] fish[i];
    }
    for (int i = 0; i < n-1; ++i) {
      cout<<result[i]<<", ";
    }
    cout<<result[n-1]<<endl;
    cout<<"Number of fish expected: "<<Max<<endl;
    cout<<endl;
  }
  return 0;
}
