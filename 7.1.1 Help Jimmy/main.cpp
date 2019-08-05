// POJ 1661

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct board {
  int left_x;
  int right_x;
  int height;
  // bool operator < (const board &rhs) const{
  //   return height > rhs.height;
  // }
};

bool cmp(const board &lhs, const board &rhs){
  return lhs.height > rhs.height;
}

board boards[1010];

map<int, int> V[1010];
int Max, N;

int least_land_time(int x, int board_idx) {
  if (V[board_idx].find(x) != V[board_idx].end()) return V[board_idx][x];

  int result, result2;
  // try left
  int left_dis = x - boards[board_idx].left_x;
  int tmp = board_idx + 1;
  for (; tmp <= N && 
  !(boards[tmp].left_x <= boards[board_idx].left_x &&
  boards[tmp].right_x >= boards[board_idx].left_x);
   ++tmp);
  if (tmp == N + 1){
    int gap = boards[board_idx].height;
    if (gap > Max) result = 20001;
    else {
      result = gap + left_dis;
    }
  } else {
    int gap = boards[board_idx].height - boards[tmp].height;
    if (gap > Max) result = 20001;
    else {
      result = gap + left_dis + least_land_time(boards[board_idx].left_x, tmp);
    }
  }
  // try right
  int right_dis = boards[board_idx].right_x - x;
  tmp = board_idx + 1;
  for (; tmp <= N && 
  !(boards[tmp].left_x <= boards[board_idx].right_x &&
  boards[tmp].right_x >= boards[board_idx].right_x);
   ++tmp);
  if (tmp == N + 1){
    int gap = boards[board_idx].height;
    if (gap > Max) result2 = 20001;
    else {
      result2 = gap + right_dis;
    }
  } else {
    int gap = boards[board_idx].height - boards[tmp].height;
    if (gap > Max) result2 = 20001;
    else {
      result2 = gap + right_dis + least_land_time(boards[board_idx].right_x, tmp);
    }
  }
  result = result < result2?result:result2;
  V[board_idx][x] = result;
  return result;
}

int main(int argc, char const *argv[])
{
  int m; cin>>m;
  int n, x, y;
  for (int i = 0; i < m; ++i){
    cin>>N>>x>>y>>Max;
    board b; b.left_x = b.right_x = x;
    b.height = y;
    boards[0] = b;
    for (int j = 1; j <= N; ++j){
      board b;
      cin>>b.left_x>>b.right_x>>b.height;
      boards[j] = b;
    }
    sort(boards + 1, boards+N+1, cmp);
    for (int j = 0; j <= N; ++j){
      V[j].clear();
    }
    cout<<least_land_time(x, 0)<<endl;
  }
  return 0;
}
