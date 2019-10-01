#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(int argc, const char** argv) {
    string email, user, my_email;
    char pass[51];
    
    int n, cnt=0, len;
    cin>>my_email>>n;
    for (int i = 0; i < n; ++i) {
        cin>>user>>pass>>email;
        if (my_email==email) {
            len = strlen(pass);
            for (int i = 0; i < len; ++i) {
                if (isupper(pass[i])) pass[i] = tolower(pass[i]);
                else if (islower(pass[i])) pass[i] = toupper(pass[i]);
            }
            cout<<user<<" "<<pass<<endl;
            cnt++;
        }
    }
    if (cnt == 0) cout<<"empty"<<endl;
    return 0;
}