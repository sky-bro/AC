#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int res = 0;
        int left = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                ++left;
            } else {
                // ]
                --left;
                if (left < 0) {
                    left += 2;
                    ++res;
                }
            }
        }
        return res;
    }
};
