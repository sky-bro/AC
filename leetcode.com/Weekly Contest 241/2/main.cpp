#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (n - 1 >= hour) return -1;
        int lo = 1, hi = 1e9;
        auto chk = [&](double x) {
            double cur = 0;
            for (int i = 0; i < n; ++i) {
                cur += dist[i] / x;
                // if (abs(cur - int(cur)) > 1e-5) cur = int(cur) + 1;
                if (cur < hour || abs(cur - hour) < 1e-9) {
                    if (abs(cur - int(cur)) > 1e-10) cur = int(cur) + 1;
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        };
        while (lo < hi) {
            double mi = (lo + hi) / 2;
            // cout << "[lo, hi, mid]:" << lo << " " << hi << " " << hour << endl;
            if (chk(mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> A = {1,1,100000};
    cout << s.minSpeedOnTime(A, 2.01);
    return 0;
}

