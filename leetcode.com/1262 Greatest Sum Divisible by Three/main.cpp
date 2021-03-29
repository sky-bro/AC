#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        priority_queue<int> one, two;
        int res = 0;
        for (int x: nums) {
            res += x;
            if (x % 3 == 1) {
                one.push(x);
                if (one.size() > 2) one.pop();
            } else if (x % 3 == 2) {
                two.push(x);
                if (two.size() > 2) two.pop();
            }
        }
        int r = INT32_MAX;
        if (res % 3) {
            if (res % 3 == 2) swap(one, two);
            if (!one.empty()) {
              if (one.size() == 2) one.pop();
              r = one.top();
            }
            if (two.size() == 2) {
                int t = two.top(); two.pop();
                r = min(r, t + two.top());
            }
        } else r = 0;
        return res - r;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> A = {2,6,2,2,7};
    Solution s;
    cout << s.maxSumDivThree (A) << endl;
    return 0;
}

