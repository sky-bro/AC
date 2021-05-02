#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef unsigned long long ull;
class Solution {
public:
    bool splitString(string s) {
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            ull x = stoull(s.substr(0, i));
            int j = i;
            for (--x; x >= 0 && j < n; --x) {
                while (s[j] == '0') ++j;
                if (j == n) {
                    if (x == 0) return true;
                    --j;
                    break;
                }
                string t = to_string(x);
                if (s.find(t, j) == j) j += t.size();
                else break;
            }
            if (j == n) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    string s = "99999999999999999998";
    Solution ss;
    cout << ss.splitString(s) << endl;
    return 0;
}

