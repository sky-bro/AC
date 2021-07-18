#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        int n = text.size();
        int st[256] = {};
        for (char c: brokenLetters) st[c] = 1;
        for (int i = 0, j; i < n; i += j + 1) {
            j = 0;
            bool broken = false;
            while (i + j < n && text[i+j] != ' ') {
                if (st[text[i + j]]) broken = true;
                ++j;
            }
            res += !broken;
        }
        return res;
    }
};
