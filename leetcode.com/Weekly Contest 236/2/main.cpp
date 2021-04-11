#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = (res + k) % i;
        }
        return res + 1;
    }
};
