#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
private:
    int binary_search(int l, int r) {
        if (l == r) return l;
        int m = l + (r - l) / 2;
        if (isBadVersion(m)) return binary_search(l, m);
        else return binary_search(m+1, r);
    }
public:
    int firstBadVersion(int n) {
        return binary_search(1, n);
    }
};