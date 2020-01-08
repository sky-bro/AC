#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    inline int C_a_b(int a, int b) {
        int result = 1;
        for (int i = 0; i < b; ++i) {
            result *= (a-i);
        }
        for (int i = 1; i <= b; ++i) {
            result /= i;
        }
        return result;
    }
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1);
        for (int i = 0; i <= rowIndex/2; ++i) {
            row[i] = row[rowIndex-i] = C_a_b(rowIndex, i);
        }
        return row;
    }
};