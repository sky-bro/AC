// 滑雪(百练1088)
// 从小到大排序, 遍历更新

#include <iostream>
#include <algorithm>

using namespace std;

struct tile {
  int height;
  int v = 1;
  int i;
  int j;
};

tile tiles[10010];
tile* matrix[100][100];


bool cmp(tile &lhs, tile &rhs){
  return lhs.height < rhs.height;
}

int main(int argc, char const *argv[])
{
  int r, c; cin>>r>>c;
  int cnt = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin>>tiles[cnt].height;
      tiles[cnt].i = i;
      tiles[cnt].j = j;
      matrix[i][j] = &tiles[cnt];
      ++cnt;
    }
  }
  sort(tiles, tiles+cnt, cmp);
  for (int i = 0; i < cnt; ++i){
    int ii = tiles[i].i;
    int ij = tiles[i].j;
    matrix[ii][ij] = &tiles[i];
  }
  int result = 1;
  for (int i = 0; i < cnt; ++i){
    int ii = tiles[i].i;
    int ij = tiles[i].j;
    int ih = tiles[i].height;
    int tmp_height;
    if (ii == 0) {
      if (ii+1 < r && matrix[ii+1][ij]->height < ih) {
        tmp_height = matrix[ii+1][ij]->v + 1;
        if (tmp_height > tiles[i].v){
          tiles[i].v = tmp_height;
        }
      }
      if (ij == 0){
        if (ij+1 < c && matrix[ii][ij+1]->height < ih) {
          tmp_height = matrix[ii][ij+1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      } else if (ij == c-1){
        if (matrix[ii][ij-1]->height < ih) {
          tmp_height = matrix[ii][ij-1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      } else {
        if (matrix[ii][ij+1]->height < ih) {
          tmp_height = matrix[ii][ij+1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
        if (matrix[ii][ij-1]->height < ih) {
          tmp_height = matrix[ii][ij-1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      }
    } else if (ii == r-1) {
      if (matrix[ii-1][ij]->height < ih) {
        tmp_height = matrix[ii-1][ij]->v + 1;
        if (tmp_height > tiles[i].v){
          tiles[i].v = tmp_height;
        }
      }
      if (ij == 0){
        if (ij+1 < c && matrix[ii][ij+1]->height < ih) {
          tmp_height = matrix[ii][ij+1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      } else if (ij == c-1){
        if (matrix[ii][ij-1]->height < ih) {
          tmp_height = matrix[ii][ij-1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      } else {
        if (matrix[ii][ij+1]->height < ih) {
          tmp_height = matrix[ii][ij+1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
        if (matrix[ii][ij-1]->height < ih) {
          tmp_height = matrix[ii][ij-1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      }
    } else {
      if (matrix[ii+1][ij]->height < ih) {
        tmp_height = matrix[ii+1][ij]->v + 1;
        if (tmp_height > tiles[i].v){
          tiles[i].v = tmp_height;
        }
      }
      if (matrix[ii-1][ij]->height < ih) {
        tmp_height = matrix[ii-1][ij]->v + 1;
        if (tmp_height > tiles[i].v){
          tiles[i].v = tmp_height;
        }
      }
      if (ij == 0){
        if (ij+1 < c && matrix[ii][ij+1]->height < ih) {
          tmp_height = matrix[ii][ij+1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      } else if (ij == c-1){
        if (matrix[ii][ij-1]->height < ih) {
          tmp_height = matrix[ii][ij-1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      } else {
        if (matrix[ii][ij+1]->height < ih) {
          tmp_height = matrix[ii][ij+1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
        if (matrix[ii][ij-1]->height < ih) {
          tmp_height = matrix[ii][ij-1]->v + 1;
          if (tmp_height > tiles[i].v){
            tiles[i].v = tmp_height;
          }
        }
      }
    }
    if (tiles[i].v > result) result = tiles[i].v;
  }
  cout<<result<<endl;
  return 0;
}
