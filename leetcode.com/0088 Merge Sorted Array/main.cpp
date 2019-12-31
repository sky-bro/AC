#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m+n);
        int idx1 = 0, idx2 = 0, idx3 = 0;
        for (; idx1 < m && idx2 < n; ) {
            if (nums1[idx1] < nums2[idx2]) {
                nums3[idx3++] = nums1[idx1++];
            } else {
                nums3[idx3++] = nums2[idx2++];
            }
        }

        for (; idx1 != m; ) nums3[idx3++] = nums1[idx1++];
        for (; idx2 != n; ) nums3[idx3++] = nums2[idx2++];
        for (int i = 0; i < idx3; ++i) nums1[i] = nums3[i];
    }
};