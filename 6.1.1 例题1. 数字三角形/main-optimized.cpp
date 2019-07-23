#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int D[MAX][MAX];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* maxSum = D[n-1];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <=i; ++j){
            cin>>D[i][j];
        }
    }
    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j){
            maxSum[j] = max(maxSum[j], maxSum[j+1]) + D[i][j];
        }
    }
    cout<<maxSum[0]<<endl;
    return 0;
}

