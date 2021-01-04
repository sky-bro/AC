#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> A;

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

int sum(int i) {  // A[1] + A[2] + ... + A[i]
  int res = 0;
  while (i) res += A[i], i -= i & -i;
  return res;
}

void add(int i, int k) {  // adds k to A[i]
  while (i <= n) A[i] += k, i += i & -i;
}

int main(int argc, char const *argv[]) {
  cout << "input the number of elements to be added, n: ";
  cin >> n;
  A.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[0];
    add(i, A[0]);
  }
//   printArr(A);
  while (1) {
    cout << "get sum of first x elements, x: ";
    int x;
    cin >> x;
    if (x > 0 && x <= n)
      cout << "sum of first " << x << " elements is " << sum(x) << endl;
    else
      break;
  }
  return 0;
}
