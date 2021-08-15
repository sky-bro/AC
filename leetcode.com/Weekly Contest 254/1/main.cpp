#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (string s: patterns) {
            if (word.find(s) != string::npos) ++res;
        }
        return res;
    }
};
