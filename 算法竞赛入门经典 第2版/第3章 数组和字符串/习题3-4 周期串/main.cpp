#include <iostream>
#include <cstring>

using namespace std;

char str[81];

int main(int argc, const char **argv)
{
    scanf("%s", str);
    int len = strlen(str), T = 1, j;
    for (; T <= len / 2; ++T)
    {
        if (len % T)
            continue;
        j = T;
        for (int i = 0; str[j]; i = 0, j += T)
        {
            for (int k = j; str[i] == str[k] && i < T; ++i, ++k)
                ;
            if (i != T)
                break;
        }
        if (j == len)
        {
            printf("%d\n", T);
            return 0;
        }
    }
    printf("%d\n", len);
    return 0;
}