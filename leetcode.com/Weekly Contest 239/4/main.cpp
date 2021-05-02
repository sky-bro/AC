#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& A, vector<int>& Q0) {
        int n = A.size(), m = Q0.size();
        vector<pair<int,int>> Q; Q.reserve(m);
        for (int i = 0; i < m; ++i) Q.emplace_back(Q0[i], i);
        sort(Q.begin(), Q.end());
        vector<int> res(m, -1);
        vector<vector<int>> A2 = A;
        sort(A.begin(), A.end());
        sort(A2.begin(), A2.end(), [](const vector<int>&l, const vector<int>&r){
            return l[1] < r[1] || (l[1] == r[1] && l[0] < r[0]);
        });
        int i = 0, j = 0;
        multiset<int> st;
        for (auto& q: Q) {
            while (i < n && A[i][0] <= q.first) {
                // insert
                st.insert(A[i][1] - A[i][0] + 1);
                ++i;
            }
            while (j < n && A2[j][1] < q.first) {
                // remove
                st.erase(st.find(A2[j][1] - A2[j][0] + 1));
                ++j;
            }
            if (!st.empty()) res[q.second] = *st.begin();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> A = {{1,4}, {2,4}, {3,6}, {4,4}};
    vector<int> Q = {2,3,4,5};
    s.minInterval(A, Q);
    return 0;
}

