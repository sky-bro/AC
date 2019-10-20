#include <iostream>
#include <cstring>
using namespace std;

const int N = 100;

int dp[N][N];
int result[N][N];

char str1[N];
char str2[N];

// 递归
int LCS(const char *str1, int len1, const char *str2, int len2)
{
    if (len1 == 0 || len2 == 0)
        return 0;

    if (dp[len1][len2] != -1)
        return dp[len1][len2];

    if (str1[len1 - 1] == str2[len2 - 1])
    {
        dp[len1 - 1][len2 - 1] = LCS(str1, len1 - 1, str2, len2 - 1);
        result[len1][len2] = 3;
        return 1 + dp[len1 - 1][len2 - 1];
    }
    else
    {
        int seq_len1 = LCS(str1, len1 - 1, str2, len2);
        int seq_len2 = LCS(str1, len1, str2, len2 - 1);
        dp[len1 - 1][len2] = seq_len1;
        dp[len1][len2 - 1] = seq_len2;
        if (seq_len1 > seq_len2)
        {
            result[len1][len2] = 1;
            return seq_len1;
        }
        else
        {
            result[len1][len2] = 2;
            return seq_len2;
        }
    }
}

// 递推
void LCS2(const char *str1, int len1, const char *str2, int len2)
{
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result[i][j] = 3;
            }
            else if (result[i - 1][j] > result[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                result[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                result[i][j] = 2;
            }
        }
    }
}

void print_sequence(int len1, int len2)

{
    if (len1 == 0 || len2 == 0)
        return;
    switch (result[len1][len2])
    {
    case 1:
        print_sequence(len1 - 1, len2);
        break;
    case 2:
        print_sequence(len1, len2 - 1);
        break;
    case 3:
        print_sequence(len1 - 1, len2 - 1);
        cout << str1[len1 - 1];
        break;
    }
}

void clear(int len1, int len2)
{
    for (int i = 0; i < len1; ++i)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < len1; ++j)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            dp[i][j] = -1;
        }
    }
}

int main(int argc, const char **argv)
{
    if (argc >= 3)
    {
        strncpy(str1, argv[1], N);
        strncpy(str2, argv[2], N);
    }
    else
    {
        string s1, s2;
        cin >> s1 >> s2;
        strncpy(str1, s1.c_str(), N);
        strncpy(str2, s2.c_str(), N);
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    clear(len1, len2);
    cout << LCS(str1, len1, str2, len2) << endl;
    print_sequence(len1, len2);
    cout << endl;

    clear(len1, len2);
    LCS2(str1, len1, str2, len2);
    cout << dp[len1][len2] << endl;
    print_sequence(len1, len2);
    cout << endl;

    return 0;
}