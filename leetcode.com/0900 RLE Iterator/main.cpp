#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class RLEIterator {
 private:
  vector<int> A;
  int i, N;

 public:
  RLEIterator(vector<int>& A) : A(A), N(A.size()), i(0) {}

  int next(int n) {
    while (n) {
      if (i >= N) return -1;
      if (A[i] < n) {
        n -= A[i];
        i += 2;
      } else {
        A[i] -= n;
        return A[i + 1];
      }
    }
    return 123;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> A = {3, 8, 0, 9, 2, 5};
  RLEIterator it(A);
  cout << it.next(2) << endl;
  cout << it.next(1) << endl;
  cout << it.next(1) << endl;
  cout << it.next(2) << endl;

  return 0;
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
