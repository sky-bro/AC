#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

// root is at 0
const int MAX_NUMBER_OF_NODES = 2e5+5, MAX_ASCII_CODE = 128;
int tr[MAX_NUMBER_OF_NODES][MAX_ASCII_CODE], id = 0; // all 0s

void insert(string s) {
    int p = 0, i = 0;
    while (i < s.size()) {
        if (!tr[p][s[i]]) tr[p][s[i]] = ++id;
        p = tr[p][s[i]];
        ++i;
    }
}
