/**
 * 三次称量，给出哪个硬币是假的，并给出其是轻了还是重了
 * POJ 1013
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char Left[3][7];
char Right[3][7];
char Result[3][7];

bool isFake(char c, bool light);

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        for (int i = 0; i < 3; ++i){
            scanf("%s%s%s", Left[i], Right[i], Result[i]);
        }
        for (char c = 'A'; c<='L'; ++c){
            if (isFake(c, true)){
                printf("%c is the counterfeit coin and it is light.\n", c);
            } else if (isFake(c, false)) {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
                break;
            }
        }
    }
    return 0;
}

bool isFake(char c, bool light){
    char *l, *r;
    
    for (int i = 0; i < 3; ++i){
        if (light){
            l = Left[i];
            r = Right[i];
        } else {
            l = Right[i];
            r = Left[i];
        }
        
        // if (strchr(l, c)){
        //     if(Result[i][0] != 'd'){
        //         return true;
        //     }
        // } else if (strchr(r, c)){
        //     if (Result[i][0] != 'u'){
        //         return true;
        //     }
        // } else {
        //     if (Result[i][0] != 'e'){
        //         return true;
        //     }
        // }
        switch(Result[i][0]){
            case 'e':
            if (strchr(l, c) || strchr(r, c))
            return false;
            break;
            case 'u':
            if (strchr(r, c) == NULL)
            return false;
            break;
            case 'd':
            if (strchr(l, c) == NULL)
            return false;
            break;

        }
    }
    return true;
}