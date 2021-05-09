#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

const int MOD = 1e9 + 7;
typedef unsigned long long ull;
typedef long long ll;
class Solution {
public:
    int maxSumMinProduct(vector<int>& A) {
        ull res = 0;
        int n = A.size();
        vector<ull> B(n);
        // 单调栈
        stack<pair<int,ull>> stk;
        for (int i = 0; i < n; ++i) {
            ull S = 0;
            while (!stk.empty() && A[i] <= stk.top().first) {
                S += stk.top().second;
                stk.pop();
            }
            S += A[i];
            B[i] = S*A[i];
            stk.emplace(A[i], S);
        }
        stack<pair<int,ull>> stk2;
        for (int i = n - 1; i >= 0; --i) {
            ull S = 0;
            while (!stk2.empty() && A[i] <= stk2.top().first) {
                S += stk2.top().second;
                stk2.pop();
            }
            B[i] += S*A[i];
            S += A[i];
            stk2.emplace(A[i], S);
        }
        return (*max_element(B.begin(), B.end()))%MOD;
    }
};
