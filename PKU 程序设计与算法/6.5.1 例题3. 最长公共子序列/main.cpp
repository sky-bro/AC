// POJ 1458

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char a[1000];
char b[1000];
int maxLen[1000][1000];

int LCS(const char *a, const char *b){
    int alen = strlen(a);
    int blen = strlen(b);
    for (int i = 0; i <= alen; ++i){
        maxLen[i][0] = 0;
    }
    for (int j = 0; j <= blen; ++j){
        maxLen[0][j] = 0;
    }
    for (int i = 1; i <= alen; ++i){
        for (int j = 1; j <= blen; ++j){
            if (a[i-1] == b[j-1]){
                maxLen[i][j] = maxLen[i-1][j-1] + 1;
            } else {
                maxLen[i][j] = max(maxLen[i-1][j], maxLen[i][j-1]);
            }
        }
    }
    return maxLen[alen][blen];
}

int main(int argc, const char** argv) {
    while (cin>>a>>b){
        cout<<LCS(a,b)<<endl;
    }
    return 0;
}