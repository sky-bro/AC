#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // not used
    inline bool is_prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i < n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> isPrime(n, true);
        for (int i = 2; i * i < n; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }

        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) ++count;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.countPrimes(10)<<endl;
    return 0;
}
