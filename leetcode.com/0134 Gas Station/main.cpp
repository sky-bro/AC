#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            gas[i] -= cost[i];
        }
        for (int i = 0; i < n; ) {
            // pass all neg
            for (; i < n && gas[i] < 0 ; ++i);
            if (i == n) break;

            // start from the first non-negative num
            int sum = gas[i], j = (i+1)%n;
            for (; sum >= 0 && j != i; sum += gas[j], j = (j+1)%n);
            if (sum >= 0) return i;

            // pass all pos
            for (++i; i < n && gas[i] >= 0; ++i);
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> gas = {3,3,4};
    vector<int> cost = {3,4,4};
    Solution s;
    cout<<s.canCompleteCircuit(gas, cost)<<endl;
    return 0;
}
