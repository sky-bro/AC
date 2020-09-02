#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  double get_poured(int r, int c, vector<vector<double>> &tower) {
    if (tower[r][c] >= 0) return tower[r][c];
    if (r == c) {
      // (r, c) only has left parent
      double l_res = get_poured(r - 1, c - 1, tower);
      if (l_res <= 1)
        return tower[r][c] = 0;
      else
        return tower[r][c] = (l_res - 1) / 2;
    } else if (c == 0) {
      // (r, c) only has right parent
      double r_res = get_poured(r - 1, c, tower);
      if (r_res <= 1)
        return tower[r][c] = 0;
      else
        return tower[r][c] = (r_res - 1) / 2;
    } else {
      // (r, c) has two parents
      double l_res = get_poured(r - 1, c - 1, tower);
      double r_res = get_poured(r - 1, c, tower);
      if (l_res <= 1) l_res = 1;
      if (r_res <= 1) r_res = 1;
      return tower[r][c] = (l_res + r_res - 2) / 2;
    }
  }

 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> tower(query_row + 1,
                                 vector<double>(query_row + 1, -1));
    tower[0][0] = poured;
    double res = get_poured(query_row, query_glass, tower);
    return res >= 1 ? 1 : res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int poured = 40, r = 8, c = 2;  // 0.59375
  cout << s.champagneTower(poured, r, c) << endl;
  while (cin >> poured >> r >> c)
    cout << s.champagneTower(poured, r, c) << endl;
  return 0;
}
