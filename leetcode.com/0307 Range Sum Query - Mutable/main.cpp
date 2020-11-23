#include <iostream>
#include <vector>

using namespace std;

// segment tree ref: https://www.youtube.com/watch?v=Oq2E2yGadnU

class NumArray {
private:
    int n;
    vector<int> segment_tree;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segment_tree.resize(2*n);
        for (int i = 0; i < n; ++i) {
            segment_tree[i+n] = nums[i];
        }
        for (int i = n-1; i > 0; --i) {
            segment_tree[i] = segment_tree[i<<1] + segment_tree[i<<1|1];
        }
    }
    void update(int i, int val) {
        i += n;
        if (segment_tree[i] == val) return;
        for (segment_tree[i] = val; i > 1; i >>= 1) {
            segment_tree[i>>1] = segment_tree[i] + segment_tree[i^1];
        }
    }
    int sumRange(int i, int j) { // sum range [i, j]
        int sum = 0;
        for (i += n, j += n+1; i < j; i >>= 1, j >>= 1) {
            if (i&1) sum += segment_tree[i++];
            if (j&1) sum += segment_tree[--j];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */