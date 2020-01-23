#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (!set.count(n)) {
            if (n == 1) return true;
            set.insert(n);
            int tmp = n;
            n = 0;
            while (tmp) {
                n += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }
        }
        return false;
    }
};