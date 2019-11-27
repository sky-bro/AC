/*
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        /*
        Symbol       Value
        I             1
        V             5
        X             10
        L             50
        C             100
        D             500
        M             1000
        */
        string res = "";
        map<int, char> m = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
        int base = 1000;
        while (num) {
            int tmp = num / base;
            if (tmp == 4) {
                res.push_back(m[base]);
                res.push_back(m[base*5]);
            } else if (tmp == 9) {
                res.push_back(m[base]);
                res.push_back(m[base*10]);
            } else if (tmp >= 5) {
                res.push_back(m[base*5]);
                for (int i = 5; i < tmp; ++i)
                    res.push_back(m[base]);
            } else if (tmp > 0){
                for (int i = 0; i < tmp; ++i)
                    res.push_back(m[base]);
            }
            num %= base;
            base /= 10;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int x;
    while (cin>>x){
        cout<<s.intToRoman(x)<<endl;
    }
    
    return 0;
}
