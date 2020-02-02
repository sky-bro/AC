#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int target, m, n;
    bool helper(vector<vector<int>> &matrix, int r1, int c1, int r2, int c2) {
        if (c1 > c2 || r1 > r2) return false;
        int r3 = r1 + (r2 - r1) / 2, c3 = c1 + (c2 - c1) / 2;
        if (matrix[r3][c3] == target) return true;
        else if (matrix[r3][c3] > target) {
            if (helper(matrix, r1, c1, r2, c2-1)) return true;
            if (helper(matrix, r1, c2, r2-1, c2)) return true;
            return false;
        } else {
            if (helper(matrix, r3 + 1, c1, r2, c2)) return true;
            if (helper(matrix, r1, c3 + 1, r3, c2)) return true;
            return false;
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        this->target = target;
        m = matrix.size();
        n = matrix[0].size();
        return helper(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
};