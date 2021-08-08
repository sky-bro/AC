#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        ll res = 0;
        for (int x: piles) {
            pq.push(x);
            res += x;
        }
        while (k--) {
            int x = pq.top(); pq.pop();
            res -= x / 2;
            x -= x/2;
            pq.push(x);
        }
        return res;
    }
};
