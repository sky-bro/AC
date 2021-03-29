#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int p1[3] = {0, 0, 0}, p2[3];
        for (int x: nums) {
            p2[0] = p1[0], p2[1] = p1[1], p2[2] = p1[2];
            for (int i = 0; i < 3; ++i) {
                int v = p2[i] + x;
                int index = (v) % 3;
                p1[index] = max(p1[index], v);
            }
        }
        return p1[0];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> A = {2,6,2,2,7};
    Solution s;
    cout << s.maxSumDivThree (A) << endl;
    return 0;
}
