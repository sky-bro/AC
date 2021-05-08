#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

int n;

typedef unsigned long long ull;

ull str_hash(const string &s) {
    ull h = 0, p = 133;
    for (char c: s) h = h*p + c;
    return h;
}

int solve() {
    cin >> n;
    set<ull> st;
    int cnt = 0;
    while (n--) {
        string s;
        cin >> s;
        if (st.emplace(str_hash(s)).second) ++cnt;
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    cout << solve() << endl;
    return 0;
}
