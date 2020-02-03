#include <iostream>
#include <queue>

using namespace std;

// dp solution, awesome, O(n) extra space
class Solution {
public:
    int numSquares(int n) {
        vector<int> table(n + 1, 0);
        for (int i = 1; i <= n; ++ i) {
            table[i] = i;
            for (int j = 1; j * j <= i; ++ j) {
                table[i] = min(table[i], table[i - j * j] + 1);
            }
        }
        return table[n];
    }
};