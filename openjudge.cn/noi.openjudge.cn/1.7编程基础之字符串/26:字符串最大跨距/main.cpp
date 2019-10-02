#include <iostream>
#include <cstring>

using namespace std;

char a[350];
char *b;
char *c;

int main(int argc, const char** argv) {
    scanf("%s", a);
    int lenA = strlen(a), flag = 0;
    for (int i = 0; i < lenA; ++i) {
        if (a[i] == ',') {
            if (flag == 0) {
                flag++;
                a[i] = 0;
                b = a + i + 1;
            } else if (flag == 1) {
                a[i] = 0;
                c = a + i + 1;
                break;
            }
        }
    }
    int lenB = strlen(b), lenC = strlen(c);
    string S = a;
    // 注意find和find_first_of的区别
    int left_b = S.find(b);
    int right_c = S.rfind(c);
    // cout<<b<<" "<<c<<endl;
    // cout<<left_b<<" "<<right_c<<endl;
    if (right_c <= left_b + lenB - 1) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<right_c - left_b - lenB<<endl;
    return 0;
}