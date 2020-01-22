#include <iostream>
#include <vector>

using namespace std;

// naive O(1) extra space, TLE
class Solution0 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); k %= n;
        for (int i = 0; i < k; ++i) {
            int tmp = nums[n-1];
            for (int j = 0; j < n; ++j) {
                swap(tmp, nums[j]);
            }
        }
    }
};

// O(1) extra space, O(n) time, math
class Solution {
private:
    int gcd(int a, int b) {
        if (a % b) return gcd(b, a % b);
        return b;
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); k %= n;
        if (k == 0) return;
        int p = gcd(k, n), q = n / p;
        for (int i = 0; i < p; ++i) {
            int tmp = nums[n-k+i];
            for (int j = 0; j < q; ++j) {
                swap(tmp, nums[(i+j*k)%n]);
            }
        }
    }
};