#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); i += 2) {
            s[i+1] = s[i] + (s[i+1] - '0');
        }
        return s;
    }
};
