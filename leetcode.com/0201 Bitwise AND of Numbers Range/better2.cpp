#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int c=0;
	    while(m!=n){
            m>>=1;
            n>>=1;
            ++c;
        }
        return n<<c;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int m, n;
    while (cin>>m>>n)
        cout<<s.rangeBitwiseAnd(m, n)<<endl;
    return 0;
}
