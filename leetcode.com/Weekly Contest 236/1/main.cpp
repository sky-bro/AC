#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool pos = true;
        for (int x: nums) {
            if (x == 0) return 0;
            if (x < 0) pos = !pos;
        }
        return pos ? 1 : -1;
    }
};
