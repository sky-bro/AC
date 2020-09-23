#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0;
        int n = A.size();
        for (int i = 0; i + 2 < n; ) {
            int l = i;
            for (; i + 1 < n && A[i + 1] > A[i]; ++i)
                ;
            if (i == l) {
                ++i;
                continue;
            }
            for (; i + 1 < n && A[i + 1] < A[i]; ++i)
                ;
            if (A[i] < A[i - 1]) res = max(res, i - l + 1);
        }
        return res;
    }
};

