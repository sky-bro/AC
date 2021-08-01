#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;

class Solution {
public:
    ll numberOfWeeks(vector<int>& A) {
        ll s = accumulate(A.begin(), A.end(), 0ll);
        ll mx = *max_element(A.begin(), A.end());
        return min(s, (2*(s - mx) + 1));
    }
};
