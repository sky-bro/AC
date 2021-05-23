#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0;
        for (int i = 0, n = s.size(), cur = 0, pre = '2'; i < n; ++i) {
            if (s[i] == pre) {
                ++cur;
            } else {
                cur = 1;
                pre = s[i];
            }
            if (s[i] == '0') zero = max(zero, cur);
            else one = max(one, cur);
        }
        return one > zero;
    }
};
