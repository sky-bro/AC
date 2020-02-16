#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class ProductOfNumbers {
 private:
  vector<int> nums;

 public:
  ProductOfNumbers() { nums.clear(); }

  void add(int num) { nums.push_back(num); }

  int getProduct(int k) {
    int n = nums.size();
    int res = 1;
    for (int i = n - 1; i >= n - k; --i) {
      if (nums[i] == 0) return 0;
      res *= nums[i];
    }
    return res;
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */