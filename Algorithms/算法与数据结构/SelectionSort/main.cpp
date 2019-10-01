#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "Student.h"

using namespace std;

int main(int argc, const char** argv) {
    int n = 10;
    // Testing with int
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::printArray(arr, n);
    selectionSort(arr, n);
    SortTestHelper::printArray(arr, n);

    // Testing with double
    double ds[] = {2.1, 2.5, 1.4, 1.2};
    SortTestHelper::printArray(ds, 4);
    selectionSort(ds, 4);
    SortTestHelper::printArray(ds, 4);

    // Testing with string
    string str[] = {"D", "A", "C", "B"};
    SortTestHelper::printArray(str, 4);
    selectionSort(str, 4);
    SortTestHelper::printArray(str, 4);

    Student students[] = {
        {"sky", 60},
        {"tony", 80},
        {"kyle", 78},
        {"kyl", 78}
    };
    SortTestHelper::printArray(students, 4);
    selectionSort(students, 4);
    SortTestHelper::printArray(students, 4);

    delete[] arr;
    return 0;
}