#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double cal(){
    char s[20];
    cin>>s;
    switch (s[0])
    {
    case '+':
        return cal() + cal();
    case '-':
        return cal() - cal();
    case '*':
        return cal() * cal();
    case '/':
        return cal() / cal();
    default:
        return atof(s);
    }
}

int main(){
    cout<<cal()<<endl;
    return 0;
}