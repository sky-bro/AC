#include <iostream>

using namespace std;

void Hanoi(int n, char l, char m, char r){
    if (n == 1){
        cout << l << "->" << r<<endl;
        return ;
    }
    Hanoi(n-1, l, r, m);
    cout << l << "->" << r<<endl;
    Hanoi(n-1, m, l, r);
}
int main(){
    int n;
    cin>>n;
    Hanoi(n, 'A', 'B', 'C');
}