#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), sum = n;
        for (int i = 0; i < n - 1; ) {
            // life is all about ups and downs?
            int up_len = 0, down_len = 0;
            // always grwo from 0
            for (; i+1 < n && ratings[i+1] > ratings[i]; ++i) {
                up_len++;
            }
            for (; i+1 < n; ++i) {
                if (ratings[i+1] < ratings[i]) {
                    down_len++;
                } else if (ratings[i+1] == ratings[i]) {
                    ++i;
                    break;
                } else {
                    break;
                }
            }
            if (up_len < down_len) swap(up_len, down_len);
            // up_len in charge
            sum += (up_len+1) * up_len / 2;
            sum += (down_len-1) * down_len / 2;
        }
        return sum;
    }
};