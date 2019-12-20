#include <iostream>

using namespace std;

// 除了得到gcd还要得到使得ax + by = gcd(a, b)的x与y的值
int egcd(int a, int b, int &x, int &y) {
    if (!b) {
        x =  1;
        y = 0;
        return a;
    }
    int gcd = egcd(b, a % b, x, y);
    int tmp = y;
    y = x - a / b * y;
    x = tmp;
    return gcd;
}

int mod_inv(int a, int c) {
    int x, y;
    egcd(a, c, x, y);
    return (x + c) % c;
}

int main(int argc, char const *argv[])
{
    int a, c;
    // mod_inv(37, 840) = 613
    while (cin>>a>>c) {
        cout<<mod_inv(a, c)<<endl;
    }
    return 0;
}
