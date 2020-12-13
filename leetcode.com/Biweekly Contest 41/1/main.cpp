#include<bits/stdc++.h>

using namespace std;

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
typedef long long ll;

class Solution {
    private:
    set<char> p;
    bool chk(string &word) {
        for (char c: word) {
            if (p.count(c) == 0) return 0;
        }
        return 1;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        p.clear();
        for (char c: allowed) p.insert(c);
        int res = 0;
        for (string&word: words) res += chk(word);
        return res;
    }
};
