#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool isThree(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (i * i == n) return true;
            if (n % i == 0) return false;
        }
        return false;
    }
};
