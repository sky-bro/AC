// https://leetcode.com/problems/scramble-string/discuss/29473/Share-my-C%2B%2B-recursive-solution
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isScramble( string s1, string s2 )
    {
        if ( s1.length() != s2.length() )
            return false;
        int len = s1.length();
        if ( s1 == s2 )
            return true;
        int table1[ 26 ] = { 0 }, table2[ 26 ] = { 0 };
        for ( int i = 0 ; i < len ; i ++ )
        {
            table1[ s1[ i ] - 'a' ] ++;
            table2[ s2[ i ] - 'a' ] ++;
        }
        if ( memcmp( table1, table2, 26 * sizeof( int ) ) )
            return false;
        if ( len <= 3 )
            return true;
        for ( int i = 1 ; i < len ; i ++ )
        {
            if ( isScramble( s1.substr( 0, i ), s2.substr( 0, i ) ) &&
                isScramble( s1.substr( i, len - i ), s2.substr( i, len - i ) ) )
                return true;
            if ( isScramble( s1.substr( 0, i ), s2.substr( len - i, i ) ) &&
                isScramble( s1.substr( i, len - i), s2.substr( 0, len - i ) ) )
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string s1 = "great", s2 = "rgeat";
    cout<<boolalpha<<s.isScramble(s1, s2)<<endl; // true

    s1 = "abcd", s2 = "bcad";
    cout<<boolalpha<<s.isScramble(s1, s2)<<endl; // true

    s1 = "abcd", s2 = "bdca";
    cout<<boolalpha<<s.isScramble(s1, s2)<<endl; // true

    while (cin>>s1>>s2) {
        cout<<boolalpha<<s.isScramble(s1, s2)<<endl;
    }
    return 0;
}
