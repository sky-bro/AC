#include <iostream>
#include <vector>

using namespace std;

/*
以下是queue可以走的方向
      \   |  /
      - Queue -
      /   |  \
refer
    https://zh.wikipedia.org/wiki/%E5%90%8E_(%E5%9C%8B%E9%9A%9B%E8%B1%A1%E6%A3%8B)

雖然grandyang的解法是recursive的，但還是有做了一些加速,
後來看了一下leetcode的solution，其實這個方法就是backtracking, @@
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queens(n, string(n, '.'));
        helper(0, queens, res);
        return res;
    }
    void helper(int curRow, vector<string>& queens, vector<vector<string>>& res) {
        int n = queens.size();
        if (curRow == n) {
            res.push_back(queens);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (isValid(queens, curRow, i)) {
                //cout << "curRow=" << curRow << ",i=" << i << endl;
                queens[curRow][i] = 'Q';            //每個row都保証只有一個queue
                helper(curRow + 1, queens, res);
                queens[curRow][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& queens, int row, int col) {
        //這裡之所以沒有check 水平的col，是因為我們每個row都保証只有一個queue
        for (int i = 0; i < row; ++i) {
        /*
        加速1.只check 0到目前的row，不需要從0掃到尾巴.
        */
            if (queens[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        /*
        加速2.只掃左上對角，右下對角不需要掃
        */
            if (queens[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); --i, ++j) {
        /*
        加速3.只掃右上對角，左下對角不需要掃
        */
            if (queens[i][j] == 'Q') return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto vvs = s.solveNQueens(4);
    for (auto &vs: vvs) {
        for (auto &s: vs) {
            cout<<s<<endl;
        }
        cout<<endl;
    }
    return 0;
}
