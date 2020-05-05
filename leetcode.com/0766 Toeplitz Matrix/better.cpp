#include <iostream>
#include <vector>

using namespace std;
// from fastest solution (not faster actually, main.cpp - traversing by lines should be faster)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = R ? matrix[0].size() : 0;
        for (int i = 1; i < R; i++)
            for (int j = 1; j < C; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};
