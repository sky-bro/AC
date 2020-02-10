#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cnts(amount+1, -1);
        cnts[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin: coins) {
                if (coin > i) continue;
                if (cnts[i-coin] != -1)
                    if (cnts[i] == -1) {
                        cnts[i] = cnts[i-coin]+1;
                    } else {
                        cnts[i] = min(cnts[i], cnts[i-coin]+1);
                    }
            }
        }
        return cnts[amount];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution s;
    cout<<s.coinChange(coins, amount)<<endl; // 3

    coins = {2};
    amount = 3;
    cout<<s.coinChange(coins, amount)<<endl; // -1

    return 0;
}
