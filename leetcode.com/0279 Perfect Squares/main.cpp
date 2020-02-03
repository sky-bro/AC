#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int h = 0;
        queue<int> q;
        q.push(n);
        while (true) {
            ++h;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int tmp_n = q.front(); q.pop();
                for (int j = 1; j*j <= tmp_n; ++j) {
                    int new_n = tmp_n - j*j;
                    if (new_n == 0) return h;
                    else q.push(new_n);
                }
            }
        }
        // dumb return
        return 0;
    }
};