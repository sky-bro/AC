#include <iostream>
#include <algorithm>
#include <string.h>
#include <typeinfo>

using namespace std;

void printArr(int a[], int n){
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

template <class T>
struct A{

    bool operator()(const T & a, const T & b) const{
        return a > b;
    }
};

bool rule1(const int & a, const int & b){
    return a<b;
}

int main(){
    int a[] = {2,4,4,5,1};
    sort(a, a+(sizeof(a)/sizeof(int)), rule1);
    // cout<<binary_search(a, a+7, 3, rule1)<<endl;
    cout<<lower_bound(a, a+sizeof(a)/sizeof(int), 3, rule1)-a<<endl;
    
    cout<<upper_bound(a, a+sizeof(a)/sizeof(int), 3, rule1)-a<<endl;
    printArr(a, sizeof(a)/sizeof(int));
    return 0;
}