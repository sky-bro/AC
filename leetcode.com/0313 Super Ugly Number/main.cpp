#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ref: https://leetcode.com/problems/super-ugly-number/discuss/76298/7-line-consice-O(kn)-c%2B%2B-solution

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int primes_size = primes.size();
        vector<int> index(primes_size), ugly(n, INT32_MAX);
        ugly[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes_size; ++j) {
                ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
            }
            for (int j = 0; j < primes_size; ++j) {
                index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
            }
        }
        return ugly[n-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> primes = {2, 7, 13, 19};
    int n = 12;
    cout<<s.nthSuperUglyNumber(n, primes)<<endl;
    return 0;
}
