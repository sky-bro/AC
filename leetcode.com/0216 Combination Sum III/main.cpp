#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> combinations;
    void dfs(int k, int n, vector<int>& combination, int min_num) {
        if (k == 1) {
            if (n >= min_num && n <= 9) {
                combination.push_back(n);
                combinations.push_back(combination);
                combination.pop_back();
            }
            return;
        }
        for (int i = min_num; i <= 10-k; ++i) {
            combination.push_back(i);
            dfs(k-1, n-i, combination, i+1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        dfs(k, n, combination, 1);
        return combinations;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.combinationSum3(3, 15);
    return 0;
}
