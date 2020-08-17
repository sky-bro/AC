#include <algorithm>
#include <ctime>
#include <iostream>

#include "BFPRT.h"

using namespace std;

/**
 * print arr L
 */
void printArr(int L[], int n) {
  for (int i = 0; i < n; i += 5) {
    for (int j = i; j < n && j < i + 5; ++j) cout << L[j] << " ";
    cout << " ";
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  srand(time(0));
  int n = 30;
  while (cin >> n) {
    cout << "----------------------------------------\n";
    int *L = new int[n];
    for (int i = 0; i < n; ++i) {
      L[i] = rand() % n + 1;
    }

    cout << "L before select:\n";
    printArr(L, n);
    cout << endl;

    int k = rand() % n;
    select(L, 0, n - 1, k);
    cout << "L after select:\n";
    printArr(L, n);
    cout << "L[" << k << "] = " << L[k] << endl << endl;

    cout << "L sorted:\n";
    sort(L, L + n);
    printArr(L, n);
    cout << endl;

    delete[] L;
  }
  return 0;
}
