#include <iostream>
#include <vector>

using namespace std;

// ref: comments at https://leetcode.com/problems/coin-change/discuss/77360/C%2B%2B-O(n*amount)-time-O(amount)-space-DP-solution
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> A(amount+1, amount+1);
        A[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                A[i] = min(A[i], A[i - coin] + 1);
            }
        }
        return A[amount] > amount ? -1 : A[amount];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> coins = {5, 2, 1};
    int amount = 11;
    Solution s;
    cout<<s.coinChange(coins, amount)<<endl; // 3

    coins = {2};
    amount = 3;
    cout<<s.coinChange(coins, amount)<<endl; // -1

    return 0;
}
