#include<bits/stdc++.h>

using namespace std;

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
typedef long long ll;

template <typename T>
void printArr(const vector<T> &arr) {
    for (const T &t : arr) cout << t << " ";
    cout << endl;
}

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<ll> d(n), d2(n), d3(n), d4(n), d5(n);
        vector<int> res(n);
        for (int i = 1; i < n; ++i) {
            d[i] = nums[i] - nums[i-1];
        }
        for (int i = 1; i < n; ++i) {
            d2[i] = d2[i-1] + d[i];
            d3[n-i-1] = d3[n-i] + d[n-i];
        }
        for (int i = 1; i <n; ++i) {
            d4[i] = d4[i-1] + d2[i];
            d5[n-i-1] = d3[n-1-i] + d5[n-i];
        }
        for (int i = 0; i < n; ++i) {
            res[i] = d4[n-1] - d4[i] - (n-i-1) * d2[i];
            res[i] += d5[0] - d5[i] - (i) * d3[i];
        }
        printArr(d);
        printArr(d2);
        printArr(d3);
        printArr(d4);
        printArr(d5);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2,3,5};
    auto res = s.getSumAbsoluteDifferences(nums);
    printArr(res);
    return 0;
}
