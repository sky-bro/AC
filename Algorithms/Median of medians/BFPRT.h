#ifndef BFPRT_H
#define BFPRT_H

/**
 * put the k-th element at L[k] (0 indexed)
 */
void select(int L[], int left, int right, int k);

/**
 * actual median of medians algo
 */
int pivot(int L[], int left, int right);

/**
 * three way partition: ---[=]=[=]+++
 */
int partition(int L[], int left, int right, int pivot_index, int k);

/*
 * <= 5 elements, insertion sort, and pick the middle as partition index
 */
int partition5(int L[], int left, int right);

#endif
