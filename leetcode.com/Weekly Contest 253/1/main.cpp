#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool isPrefixString(string s, vector<string>& A) {
        int n = s.size();
        int m = A.size();
        int i = 0, j = 0;
        for (; i < n && j < m; ++j) {
            int len = A[j].size();
            for (int k = 0; k < len; ++k) {
                if (s[i] == A[j][k]) {
                    ++i;
                } else return false;

            }
        }
        return i == n;
    }
};
