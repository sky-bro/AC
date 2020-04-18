#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class KthLargest {
  vector<int> heap;
  int K;

 public:
  KthLargest(int k, vector<int>& nums) {
    auto cmp = greater<int>();
    int n = nums.size();
    K = k;
    for (int i = 0; i < n; ++i) {
      if (i < k) {
        heap.push_back(nums[i]);
        push_heap(heap.begin(), heap.end(), cmp);
      } else if (heap[0] < nums[i]) {
        pop_heap(heap.begin(), heap.end(), cmp);
        heap[k - 1] = nums[i];
        push_heap(heap.begin(), heap.end(), cmp);
      }
    }
  }

  int add(int val) {
    auto cmp = greater<int>();
    if (heap.size() != K) {
      heap.push_back(val);
      push_heap(heap.begin(), heap.end(), cmp);
    } else if (heap[0] < val) {
      pop_heap(heap.begin(), heap.end(), cmp);
      heap[K - 1] = val;
      push_heap(heap.begin(), heap.end(), cmp);
    }
    // return the smalllest (which is the kth largest if the size of heap is K)
    return heap[0];
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */