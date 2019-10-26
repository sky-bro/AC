#include <iostream>

using namespace std;

char buf[6];
int cnt[10] = {0};

int main(int argc, const char **argv)
{

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        sprintf(buf, "%d", i);
        for (int j = 0; buf[j]; ++j)
            cnt[buf[j] - '0']++;
    }
    for (int i = 0; i < 9; ++i)
    {
        printf("%d ", cnt[i]);
    }
    printf("%d\n", cnt[9]);
    return 0;
}
