#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

class Solution {
 private:
  long long f(int h, int n, vector<long long> &FAC) {
    long long res = 1;
    for (int i = 0; i < h; ++i) {
      res *= (n - i);
    }
    res /= FAC[h];
    return res;
  }

 public:
  string kthSmallestPath(vector<int> &destination, int k) {
    vector<long long> FAC(16);
    FAC[0] = FAC[1] = 1;
    for (int i = 2; i < 16; ++i) {
      FAC[i] = FAC[i - 1] * i;
    }
    int n = destination[0] + destination[1];
    int cnt_H = destination[1];
    int cnt_V = destination[0];
    string res = "";
    for (int i = 0; i < n && cnt_H && cnt_V; ++i) {
      long long d = f(cnt_H - 1, n - i - 1, FAC);
      if (d < k) {
        k -= d;
        res.push_back('V');
        --cnt_V;
      } else {
        res.push_back('H');
        --cnt_H;
      }
    }

    for (int i = 0; i < cnt_H; ++i) {
      res.push_back('H');
    }
    for (int i = 0; i < cnt_V; ++i) {
      res.push_back('V');
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> des = {15, 15};
  int k = 1;
  Solution s;
  cout << s.kthSmallestPath(des, k) << endl;
  return 0;
}
