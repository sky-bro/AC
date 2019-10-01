#ifndef SelectionSort_H
#define SelectionSort_H

#include <iostream>

using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        int min_ind = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_ind]) min_ind = j;
        }
        if (i == min_ind) continue;
        swap(arr[i], arr[min_ind]);
        // T tmp = arr[i];
        // arr[i] = arr[min_ind];
        // arr[min_ind] = tmp;
    }
}

#endif //SelectionSort_H