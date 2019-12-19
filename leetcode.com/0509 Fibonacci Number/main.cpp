#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;
        int a = 0, b = 1, result;
        for (int i = 2; i <= N; ++i) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};
