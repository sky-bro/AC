#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool canReach(string s, int a, int b) {
        int n = s.size();
        if (s[n-1] != '0') return false;
        vector<int> d;
        set<int> st;
        for (int i = 1; i < n; ++i) if (s[i] == '0') {
            st.insert(i);
        }
        stack<int> stk;
        stk.push(0);
        while (!stk.empty()) {
            int x = stk.top(); stk.pop();
            auto it = st.lower_bound(x+a);
            while (it != st.end() && *it <= x + b) {
                if (*it == n-1) return true;
                stk.push(*it);
                st.erase(it++);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string s = "011100";
    int a = 2, b = 4;
    s = "011010";
    a = 2, b = 3;
    Solution sol;
    cout << sol.canReach(s, a, b) << endl;
    return 0;
}

