#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] != i) {
                if (A[i] == i+1 && A[i+1] == i) {++i; continue;}
                return false;
            }
        }
        return true;
    }
};
