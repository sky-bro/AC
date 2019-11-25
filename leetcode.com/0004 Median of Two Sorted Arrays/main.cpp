// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/335175/Cpp-concise-O(log(min(M-N)))-solution-with-detailed-comment
/*
复杂度为O(log(m+n))
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>

using namespace std;

// [0, 1, 2, 3, 4, 5] (2, 3)->(2, 3) m/2-1 = 2
// [2, 3, 4, 5, 6] (2)->(4) (n+1)/2 = 3

// [3, 4, 5]
// [2, 3, 4] 3.5

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(!m) return (nums2[(n - 1)/2] + nums2[n /2]) / 2.0;
        if(!n) return (nums1[(m - 1)/2] + nums1[m /2]) / 2.0;
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        // 二分法在[lo, hi]中搜索合适的cntM, 也就是说nums1中取0～m个元素组成前half个元素
        int lo = 0, hi = m, cntM, half = (m + n + 1) >> 1;
		// cntM + cntN = half
        //x = nums1[cntM - 1], x' = nums1[cntM]
        //y = nums2[cntN - 1], y' = nums2[cntN]
        // we want to find a cntM which validates x >= y && x < y' or y >= x && y < x' then the median will be max(x, y)
        // since cntM is in range [0, m], and the condition is monotonic, use binary search.
        while (lo <= hi) {
            cntM = lo + (hi - lo) / 2;
            int cntN = half - cntM;
            //x > y' => x > y && x > y' then the sorted array will be like ···-> y->y'->x->···
            //we need to move left so x decreases and y increases
            if (cntM > 0 && nums1[cntM - 1] > nums2[cntN])
                hi = cntM - 1;
            //y > x' => y > x && y > x' then the sorted array will be like ···->x->x'->y->···
            else if (cntM < m && nums1[cntM] < nums2[cntN - 1])
                lo = cntM + 1;
            else
                break;
        }
        // base condition:
        // ans = max(nums1[cntM - 1], nums2[half - cntM - 1]);
        // ans2 = min(nums1[cntM], nums2[half - cntM]);
        // PAY ATTENTION TO subscript overflow
        // That is to compute cntM - 1 == -1, half - cntM - 1 == -1
        // cntM == m, half - cntM == n
        double ans;
        if (cntM == 0)
            //none of nums1 is used
            ans = nums2[half - 1];
        else if (cntM == m && cntM == half) {
            //run out of nums1, if half - cntM - 1 == -1 => cntM == half => none of nums2 is used
            ans = nums1[m - 1];
        }else
            ans = max(nums1[cntM - 1], nums2[half - cntM - 1]);
        if ((m + n) & 1 == 1)
            return ans;
        double ans2;
        if (cntM == m)
            //run out of nums1 
            ans2 = nums2[half - cntM];
        else if (cntM == 0 && half == n) {
            //the first median never uses nums1, but we run out of nums2, so we have to get nums1[0]
            ans2 = nums1[0];
        }else
            ans2 = min(nums1[cntM], nums2[half - cntM]);
        return (ans + ans2) / 2.0;

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
