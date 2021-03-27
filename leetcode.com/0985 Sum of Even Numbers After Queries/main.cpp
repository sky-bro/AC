#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& Q) {
        vector<int> res;
        int s = 0;
        for (int a: A) if ((a&1) == 0) s += a;
        for (auto &q: Q) {
            if (A[q[1]] & 1) {
                if (q[0] & 1) {
                    s += A[q[1]] + q[0];
                }
            } else {
                if (q[0] & 1) s -= A[q[1]];
                else s += q[0];
            }
            A[q[1]] += q[0];
            res.push_back(s);
        }
        return res;
    }
};
