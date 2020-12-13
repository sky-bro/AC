#include <bits/stdc++.h>

using namespace std;

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
typedef long long ll;

class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n!=1) {
            res += n/2;
            if (n&1) {
                n = 1 + n/2;
            } else {
                n >>= 1;
            }
        }
        return res;
    }
};

