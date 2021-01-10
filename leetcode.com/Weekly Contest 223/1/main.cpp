#include<bits/stdc++.h>

using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
typedef long long ll;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for (int i: encoded) {
            first = res.back() ^ i;
            res.push_back(first);
        }
        return res;
    }
};
