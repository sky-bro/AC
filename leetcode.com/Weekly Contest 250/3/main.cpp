#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;
class Solution {
public:
    ll maxPoints(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<ll> B(A[0].begin(), A[0].end());
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                B[j + 1] = max(B[j + 1], B[j] - 1);
            }
            for (int j = n - 1; j > 0; --j) {
                B[j - 1] = max(B[j - 1], B[j] - 1);
            }
            for (int j = 0; j < n; ++j) {
                B[j] += A[i][j];
            }
        }
        return *max_element(B.begin(), B.end());
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {
        {1, 2, 3},
        {1, 5, 1},
        {3, 1, 1}
    };
    A = {
        {0,3,0,4,2},
        {5,4,2,4,1},
        {5,0,0,5,1},
        {2,0,1,0,3}
    };
    Solution s;
    cout << s.maxPoints(A) << endl;
    return 0;
}

