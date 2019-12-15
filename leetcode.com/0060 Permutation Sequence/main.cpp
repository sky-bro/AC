#include <iostream>

using namespace std;

int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "", s0 = "";
        for (int i = 1; i <= n; ++i) {
            s0.push_back(i + '0');
        }
        --k;
        for (int i = n - 1; i >= 0; --i) {
            int t = k / fac[i];
            k  %= fac[i];
            s.push_back(s0[t]);
            s0.erase(t, 1);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n, k;
    while (cin>>n>>k)
        cout<<s.getPermutation(n, k)<<endl;
    return 0;
}
