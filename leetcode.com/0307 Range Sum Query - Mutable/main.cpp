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
        segment_tree[i] = val;
        while (i > 1) {
            i >>= 1;
            segment_tree[i] = segment_tree[i<<1] + segment_tree[i<<1|1];
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        j += 1;
        i += n; j += n;
        while (i < j) {
            if (i&1) {
                sum += segment_tree[i];
                ++i;
            }
            if (j&1) {
                --j;
                sum += segment_tree[j];
            }
            i >>= 1; j >>= 1;
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