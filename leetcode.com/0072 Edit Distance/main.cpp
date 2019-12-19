#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    string word1, word2;
    int len1, len2;
    vector<vector<int>> dp;

    int _minDistance(int idx1, int idx2) {
        if (dp[idx1][idx2]) return dp[idx1][idx2];
        if (idx1 == len1 && idx2 == len2) return 0;
        if (idx1 == len1) {
            return dp[idx1][idx2] = len2 - idx2;
        } 
        if (idx2 == len2) {
            return dp[idx1][idx2] = len1 - idx1;
        }
        
        // 把word1从idx1开始到末尾
        // 变为word2从idx2开始到末尾
        // 三种方式: insert/delete/replace a character

        int tmp_max = 0, tmp;
        // 1. insert
        tmp_max = 1 + _minDistance(idx1, idx2+1);
        
        // 2. delete
        tmp = 1 + _minDistance(idx1+1, idx2);
        if (tmp < tmp_max) tmp_max = tmp;

        // 3. replace
        if (word1[idx1] == word2[idx2]) {
            tmp = _minDistance(idx1+1, idx2+1);
        } else {
            tmp = 1 + _minDistance(idx1+1, idx2+1);
        }
        if (tmp < tmp_max) tmp_max = tmp;

        return dp[idx1][idx2] = tmp_max;
    }
public:
    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;
        len1 = word1.length();
        len2 = word2.length();
        dp = vector<vector<int>>(len1+1, vector<int>(len2+1, 0));
        return _minDistance(0, 0);
        // return cur_max;
    }
};


/*
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/

/*
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
int main(int argc, char const *argv[])
{
    string s1, s2;
    Solution s;
    while (cin>>s1>>s2)
        cout<<s.minDistance(s1, s2)<<endl;
    return 0;
}
