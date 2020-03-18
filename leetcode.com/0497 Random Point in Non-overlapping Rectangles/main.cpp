#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 private:
  map<int, vector<int>> m;
  int total;

 public:
  Solution(vector<vector<int>>& rects) {
    m.clear();
    total = 0;
    for (auto& rect : rects) {
      // m.emplace(total, rect);
      m[total] = rect;
      total += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
    }
  }

  vector<int> pick() {
    int i = rand() % total;
    auto it = prev(m.upper_bound(i));
    i -= it->first;
    int w = it->second[2] - it->second[0] + 1;
    vector<int> res;
    res.push_back(it->second[0] + i % w);
    res.push_back(it->second[1] + i / w);
    return res;
  }
};

template <typename T>
void printArr(const vector<T>& arr) {
  for (const T& t : arr) {
    cout << t << " ";
  }
  cout << endl;
}

int main(int argc, char const* argv[]) {
  vector<vector<int>> rects = {{1, 1, 5, 5}};
  Solution s(rects);
  printArr(s.pick());
  printArr(s.pick());
  printArr(s.pick());
  printArr(s.pick());
  return 0;
}
