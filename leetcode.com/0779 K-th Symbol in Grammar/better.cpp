#include <iostream>
#include <vector>

using namespace std;

// ref: [JAVA] one line
// https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/113705/JAVA-one-line

class Solution {
public:
    int kthGrammar(int N, int K) {
        return __builtin_popcount(K-1) & 1;
    }
};
// 0
// 01
// 0110
// 01 10 10 01
// 0110100110010110
