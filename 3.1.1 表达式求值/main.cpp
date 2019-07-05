/**
 * expression: term, +, -
 * term: factor, *, /
 * factor: number, (exp)
 */

#include <iostream>
using namespace std;

double exp();

double factor(){
    char c = cin.peek();
    double a;
    if (c == '('){
        cin.get();
        a = exp();
        cin.get();
    } else {
        cin>>a;
    }
    return a;
}

double term(){
    double a = factor();
    while (true){
        char op = cin.peek();
        if (op == '*'){
            cin.get();
            a *= factor();
        } else if (op == '/'){
            cin.get();
            a /= factor();
        } else {
            break;
        }
    }
    return a;
}

double exp(){
    double a = term();
    while (true){
        char op = cin.peek();
        if (op == '+'){
            cin.get();
            a += term();
        } else if (op == '-'){
            cin.get();
            a -= term();
        } else {
            break;
        }
    }
    return a;
}

int main(int argc, const char** argv) {
    cout<<exp()<<endl;
    return 0;
}