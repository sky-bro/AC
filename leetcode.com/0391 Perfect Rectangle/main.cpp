#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// TLE

struct cmp_by_y {
  bool operator()(const vector<int>& a, const vector<int>& b) const {
    // bottom left corner's y
    return a[1] < b[1];
  }
};

// bool cmp_by_y(vector<int>& a, vector<int>& b) {
//   // bottom left corner's y
//   return a[1] < b[1];
// }

bool cmp_by_x(const vector<int>& a, const vector<int>& b) {
  // bottom left corner's x
  return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    sort(rectangles.begin(), rectangles.end(), cmp_by_x);
    int n = rectangles.size();
    if (n == 0) return false;
    int down = rectangles[0][1], up = down;
    int left = rectangles[0][0], right = rectangles[0][2];
    int i = 0;
    for (; i < n && left == rectangles[i][0]; ++i) {
      if (rectangles[i][1] != up) return false;
      up = rectangles[i][3];
      right = min(right, rectangles[i][2]);
    }

    set<vector<int>, cmp_by_y> st;
    for (i = 0; i < n && left == rectangles[i][0]; ++i) {
      if (rectangles[i][2] > right) {
        st.insert(rectangles[i]);
      }
    }

    for (; i < n;) {
      int tmp_left = rectangles[i][0];
      if (tmp_left != right) return false;
      for (; i < n && tmp_left == rectangles[i][0]; ++i) {
        if (st.find(rectangles[i]) != st.end()) return false;
        st.insert(rectangles[i]);
      }
      auto it = st.begin();
      int tmp_up = (*it)[1];
      right = (*it)[2];
      if (tmp_up != down) return false;
      for (; it != st.end(); ++it) {
        if ((*it)[1] != tmp_up) return false;
        tmp_up = (*it)[3];
        right = min(right, (*it)[2]);
      }
      if (tmp_up != up) return false;

      for (auto it = st.begin(); it != st.end();) {
        if ((*it)[2] <= right)
          st.erase(it++);
        else
          ++it;
      }
    }

    return /*(right - left == up - down) && */ st.empty();
  }
};

int main(int argc, char const* argv[]) {
  Solution s;

  vector<vector<int>> rectangles = {{1, 1, 3, 3},
                                    {3, 1, 4, 2},
                                    {3, 2, 4, 4},
                                    {1, 3, 2, 4},
                                    {2, 3, 3, 4}};  // true
  rectangles = {{0, 0, 4, 1}, {7, 0, 8, 2}, {6, 2, 8, 3},
                {5, 1, 6, 3}, {4, 0, 5, 1}, {6, 0, 7, 2},
                {4, 2, 5, 3}, {2, 1, 4, 3}, {0, 1, 2, 2},
                {0, 2, 2, 3}, {4, 1, 5, 2}, {5, 0, 6, 1}};  // true
  cout << s.isRectangleCover(rectangles) << endl;
  return 0;
}
