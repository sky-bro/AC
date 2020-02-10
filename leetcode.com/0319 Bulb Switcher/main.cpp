#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// naive, look for pattern
// class Solution {
// public:
//     int bulbSwitch(int n) {
//         vector<bool> bulbs(n+1);
//         for (int i = 1; i <= n; ++i) {
//             for (int j = i; j <= n; j += i) {
//                 bulbs[j] = !bulbs[j];
//             }
//         }
//         int cnt = 0;
//         for (bool bulb: bulbs) {
//             cnt += bulb;
//         }
//         return cnt;
//     }
// };

// math sol
// explanation: https://leetcode.com/problems/bulb-switcher/discuss/77104/Math-solution..
class Solution {
public:
    int bulbSwitch(int n) {
        return int(sqrt(n));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while (cin>>n) {
        cout<<"\t"<<s.bulbSwitch(n)<<endl;
    }
    return 0;
}
