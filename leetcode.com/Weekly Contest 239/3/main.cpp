#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int getMinSwaps(string s, int k) {
        string t = s;
        int n = s.size();
        while (k--) {
            next_permutation(t.begin(), t.end());
            cout << t << endl;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;
            int j = i + 1;
            for (; j < n; ++j) {
                if (s[j] == t[i]) break;
            }
            while (j != i) {
                swap(s[j], s[j-1]);
                --j;
                ++cnt;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int k = 5;
    cout << s.getMinSwaps("155343", k);
    
    return 0;
}

