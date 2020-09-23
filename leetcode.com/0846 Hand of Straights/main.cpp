#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W) return false;
        map<int, int> mp;
        for (int num : hand) {
            mp[num]++;
        }
        while (!mp.empty()) {
            int pre = mp.begin()->first - 1;
            int len = 0;
            for (auto it = mp.begin(); it != mp.end() && len != W;
                  ++len) {
                if (it->first != pre + 1) {
                    return false;
                }
                pre = it->first;
                if (--it->second == 0) {
                    mp.erase(it++);
                } else {
                    ++it;
                }
            }
            if (len != W) return false;
        }
        return true;
    }
};

int main() {
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int W = 3;
    Solution s;
    cout << s.isNStraightHand(hand, W) << endl;
    return 0;
}
