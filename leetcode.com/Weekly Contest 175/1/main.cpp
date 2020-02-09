#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set;
        int cnt_zero = 0;
        for (int i: arr) {
            if (i == 0) cnt_zero ++;
            else set.insert(i);
        }
        if (cnt_zero > 1) return true;
        for (int i: arr) {
            if (set.find(i*2) != set.end()) return true; // won't find 0
            if (i % 2 == 0 && set.find(i/2) != set.end()) { // won't find 0
                return true;
            }
        }
        return false;
    }
};