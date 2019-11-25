#include <iostream>

using namespace std;

class Solution {
public:

    // 4ms
    // int numJewelsInStones(string J, string S) {
    //     bool m[0xff]={false}; // remember to initialize m to all 0
    //     int cnt = 0;
    //     for (auto c: J) m[c]=true;
    //     for (auto c: S) cnt += m[c];
    //     return cnt;
    // }

    // 0ms
    int numJewelsInStones(string J, string S) {
        bool m[0xff]={false}; // remember to initialize m to all 0
        int cnt = 0;
        for (auto it = J.begin(); it != J.end(); ++it) m[*it] = true;
        for (auto it = S.begin(); it != S.end(); ++it) cnt += m[*it];
        return cnt;
    }
};