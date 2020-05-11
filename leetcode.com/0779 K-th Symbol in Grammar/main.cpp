#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        return N != 1 && !((K&1) ^ kthGrammar(N-1, (K+1)/2));
    }
};
// 0
// 01
// 0110
// 01 10 10 01
// 0110100110010110
