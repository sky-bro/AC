#ifndef SortTestHelper_H
#define SortTestHelper_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper
{
int* generateRandomArray(int n, int low, int high)
{
    assert(low<=high);
    int *arr = new int[n];
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % (high - low + 1) + low;
    }
    return arr;
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
} // namespace SortTestHelper

#endif // !SortTestHelper_H