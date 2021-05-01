#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& R, vector<vector<int>>& Q) {
        int n = R.size(), m = Q.size();
        auto cmp = [](const vector<int>&l, const vector<int>&r) {
            return l[1] < r[1] || (l[1] == r[1] && l[0] < r[0]);
        };
        for (int i = 0; i < m; ++i) Q[i].push_back(i);
        sort(R.begin(), R.end(), cmp);
        sort(Q.begin(), Q.end(), cmp);
        vector<int> res(m, -1);
        set<int> st;
        for (int i = 0; i < n; ++i) st.insert(R[i][0]);
        int i = 0;
        for (auto &q: Q) {
            while (i < n && q[1] > R[i][1]) {
                st.erase(R[i++][0]);
            }
            if (i == n) break;
            auto it = st.lower_bound(q[0]);
            if (it != st.begin()) {
                int cur = INT32_MAX;
                if (it != st.end()) {
                    cur = *it;
                }
                auto it2 = prev(it);
                if (cur - q[0] >= q[0] - *it2) cur = *it2;
                res[q[2]] = cur;
            } else {
                res[q[2]] = *it;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    // [[23,22],[6,20],[15,6],[22,19],[2,10],[21,4],[10,18],[16,1],[12,7],[5,22]]
    // [[12,5],[15,15],[21,6],[15,1],[23,4],[15,11],[1,24],[3,19],[25,8],[18,6]]
    
    return 0;
}

