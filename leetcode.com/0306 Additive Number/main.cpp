// ref: https://leetcode.com/problems/additive-number/discuss/75623/Share-my-C%2B%2B-solutioneasy-to-understand

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Solution {
private:
    inline bool match_front(string &s1, int idx, string &s2, int len) {
        for (int i = 0; i < len; ++i) {
            if (s1[idx+i] != s2[i]) return false;
        }
        return true;
    }
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        if (n < 3) return false;
        for (int i = 1; i <= n/2; ++i) {
            // if num[0] == '0', then first number must be 0 (i is the first number's length)
            if (num[0] == '0' && i > 1) break;
            for (int j = i + 1; n - j >= max(j-i, i); ++j) {
                // same here, if second number begins with '0', it must be 0 (j-i is the second number's length)
                if (num[i] == '0' && j - i > 1) break;
                // idx is where the next number begins, when it reaches n, means num is an AdditiveNumber
                int idx = j;
                // three numbers, we need to check if num3 is valid (by using match_front function)
                ll num1 = stoll(num.substr(0, i));
                ll num2 = stoll(num.substr(i, j-i));
                ll num3 = num1 + num2;

                string num3_str = to_string(num3);
                int len = num3_str.length();
                if (idx + len > n) continue;
                // match num from idx, match next len characters
                if (!match_front(num, idx, num3_str, len)) continue;
                // matched, increase idx by len
                idx += len;

                // when first and second number is fixed, whole sequence is fixed: num3 = num1 + num2
                // check if remaining num sequence is valid
                while (idx < n) {
                    num1 = num2;
                    num2 = num3;
                    num3 = num1 + num2;
                    num3_str = to_string(num3);
                    len = num3_str.length();
                    if (idx + len > n) break;
                    if (!match_front(num, idx, num3_str, len)) break;
                    idx += len;
                }
                // found!
                if (idx == n) return true;
            }
        }
        // haven't found
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;
    while (cin>>str) {
        cout<<s.isAdditiveNumber(str)<<endl;
    }
    return 0;
}
