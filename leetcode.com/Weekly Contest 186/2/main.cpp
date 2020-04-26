#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        if (k == n) return sum;
        k = n-k;
        int cur = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
        int min_remain = cur;
        for (int i = k; i < n; ++i) {
          cur += cardPoints[i] - cardPoints[i-k];
          min_remain = min(min_remain, cur);
        }
        return sum - min_remain;
    }
};
