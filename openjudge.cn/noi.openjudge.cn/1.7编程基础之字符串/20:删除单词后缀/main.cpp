#include <iostream>
#include <cstring>

using namespace std;

char c[33];

int main(int argc, const char** argv) {
    cin>>c;
    int len = strlen(c);
    
    switch (c[len-1])
    {
    case 'r':
        if (c[len-2]=='e') c[len-2]=0;
        break;
    case 'y':
        if (c[len-2]=='l') c[len-2]=0;
        break;
    case 'g':
        if (c[len-2]=='n' && c[len-3]=='i') c[len-3]=0;
    }
    cout<<c<<endl;
    return 0;
}