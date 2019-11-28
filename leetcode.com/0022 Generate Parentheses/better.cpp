// could be improved, slower than mine somehow.
// this line (line 27) is clever:
    // else if (right <= left) { // important! it won't be valid if left < right.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        char *element = new char[2 * n];
        if (n == 0)
            return result;
        generate(result, element, n, 0, 0);
        return result;
    }

private:
    void generate(vector<string> &result, char *element, int n, int left, int right) {
        if (left == n && right == n) {
            string res = "";
            for(int i=0;i<2*n;i++)
                res.push_back(element[i]);
            result.push_back(res);
        } else if (right <= left) { // important! it won't be valid if left < right.
            if (left < n) {
                element[left + right] = '(';
                generate(result, element, n, left + 1, right);
            }
            if (right < n) {
                element[left + right] = ')';
                generate(result, element, n, left, right + 1);
            }
        }
    }
};