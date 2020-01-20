#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        long long div = 1;
        while (div * 26 <= n) div = div * 26;
        vector<int> num;
        while (div) {
            num.push_back(n / div);
            n %= div;
            div /= 26;
        }
        int len = num.size();
        for (int idx = len - 1; idx > 0; --idx) {
            if (num[idx] <= 0) {
                num[idx-1] -= 1;
                num[idx] += 26;
            }
        }
        string result = "";
        for (int i = 0; i < len; ++i) {
            if (!num[i]) continue;
            result.push_back('A' - 1 + num[i]);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while (cin>>n) {
        cout<<s.convertToTitle(n)<<endl;
    }
    return 0;
}
