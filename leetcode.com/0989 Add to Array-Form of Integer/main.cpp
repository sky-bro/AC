#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        A[0] += K;
        int n = A.size();
        for (int i = 0; i < A.size() && A[i] > 9; ++i) {
            int c = A[i] / 10;
            A[i] %= 10;
            if (i + 1 == A.size()) A.push_back(c);
            else A[i+1] += c;
        }
        reverse(A.begin(), A.end());
        return A;
    }
};
