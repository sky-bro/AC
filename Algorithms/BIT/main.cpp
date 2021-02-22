#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

template <typename T>
class fenwick {
public:
  int n;
  vector<T> A;
  fenwick(int n): n(n), A(n+1) {} // A[0] not used
  T sum(int i) {  // prefix sum: A[1] + A[2] + ... + A[i]
    T v{};
    while (i) v += A[i], i -= i & -i;
    return v;
  }
  void add(int i, T v) {  // adds v to A[i]
    while (i <= n) A[i] += v, i += i & -i;
  }
};

int main(int argc, char const *argv[]) {
  cout << "input the number of elements to be added, n: ";
  int n;
  cin >> n;
  fenwick<int> t(n); // 1-indexed
  for (int i = 1; i <= n; ++i) {
    cin >> t.A[0];
    t.add(i, t.A[0]);
  }
  printArr(t.A);
  while (1) {
    cout << "get sum of first x elements, x: ";
    int x;
    cin >> x;
    if (x > 0 && x <= n)
      cout << "sum of first " << x << " elements is " << t.sum(x) << endl;
    else
      break;
  }
  return 0;
}
