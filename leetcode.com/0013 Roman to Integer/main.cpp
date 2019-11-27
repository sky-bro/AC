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
    int romanToInt(string s) {
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
        int sum = 0;
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.length();
        int prev = 1000, cur;
        for (int i = 0; i < n; ++i) {
            cur = m[s[i]];
            sum += cur;
            if (cur > prev) {
                sum -= prev * 2;
            }
            prev = cur;
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str;
    while (cin>>str){
        cout<<s.romanToInt(str)<<endl;
    }
    
    return 0;
}
