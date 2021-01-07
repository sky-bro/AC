#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        const int N = 10000;
        vector<int> cnts(N);
        for (int num: deck) ++cnts[num];
        int X = 0;
        for (int i = 0; i < N; ++i) {
            if (!cnts[i]) continue;
            if (X) X = gcd(X, cnts[i]);
            else X = cnts[i];
        }
        return X >= 2;
    }
};
