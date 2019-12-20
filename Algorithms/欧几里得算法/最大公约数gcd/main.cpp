#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main(int argc, char const *argv[])
{
    int a, b;
    while (cin>>a>>b)
        cout<<gcd(a, b)<<endl;
    return 0;
}
