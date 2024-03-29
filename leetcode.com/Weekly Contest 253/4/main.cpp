#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        vector<int> S;
        int m = 0;
        auto chk = [&](int x) {
            if (m && S[m-1] <= x) return m;
            int l = 0, r = m - 1;
            while (l < r) {
                // x = 3
                // 1 1 2 2 3 3 (4) 4
                // 1 1 2 2 3 3 3 4
                // x = 5
                // 1 1 2 2 3 3 3 4 5
                // find first S[i] > x
                int m = (l + r) >> 1;
                if (S[m] > x) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            return l;
        };
        int j = 0;
        for (int x: A) {
            int i = chk(x);
            if (i == m) {
                ++m;
                S.push_back(x);
            } else {
                S[i] = x;
            }
            res[j++] = i + 1;
        }
        return res;
    }
};
