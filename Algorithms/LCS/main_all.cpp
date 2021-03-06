// 需要输出所有最长公共子序列，只需要改变print_sequence函数
#include <iostream>
#include <cstring>
#include <string>
#include <set>

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
        // 这两行仅为输出所有最长公共子序列时需要，仅一个最长公共子序列不需要
        dp[len1 - 1][len2] = LCS(str1, len1 - 1, str2, len2);
        dp[len1][len2 - 1] = LCS(str1, len1, str2, len2 - 1);

        dp[len1 - 1][len2 - 1] = LCS(str1, len1 - 1, str2, len2 - 1);
        // 3表示左上
        result[len1][len2] = 3;
        return dp[len1][len2] = 1 + dp[len1 - 1][len2 - 1];
    }
    else
    {
        int seq_len1 = LCS(str1, len1 - 1, str2, len2);
        int seq_len2 = LCS(str1, len1, str2, len2 - 1);
        dp[len1 - 1][len2] = seq_len1;
        dp[len1][len2 - 1] = seq_len2;
        if (seq_len1 > seq_len2)
        {
            result[len1][len2] = 1; // 1表示上
            return dp[len1][len2] = seq_len1;
        }
        else
        {
            result[len1][len2] = 2; // 2表示左
            return dp[len1][len2] = seq_len2;
        }
    }
}

// 递推
int LCS2(const char *str1, int len1, const char *str2, int len2)
{
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // 3表示左上
                result[i][j] = 3;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                // 1表示上，上面的dp值更长
                result[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                // 2表示左
                result[i][j] = 2;
            }
        }
    }
    return dp[len1][len2];
}

// 获取所有最长公共子序列
// 测试 bdcaba abcbdba
set<string> get_all_sequence(int len1, int len2)
{
    set<string> s;
    char buf[2] = {0};
    if (len1 == 0 || len2 == 0)
        return set<string>();
    
    if (dp[len1][len2] == dp[len1][len2-1]) {
        set<string> tmp = get_all_sequence(len1, len2-1);
        s.insert(tmp.begin(), tmp.end());
    }

    if (dp[len1][len2] == dp[len1-1][len2]) {
        set<string> tmp = get_all_sequence(len1-1, len2);
        s.insert(tmp.begin(), tmp.end());
    }

    if (dp[len1][len2] == dp[len1-1][len2-1]) {
        set<string> tmp = get_all_sequence(len1-1, len2-1);
        s.insert(tmp.begin(), tmp.end());
    } else if (dp[len1][len2] == dp[len1-1][len2-1] + 1 && str1[len1-1]==str2[len2-1]) {
        set<string> tmp = get_all_sequence(len1-1, len2-1);
        buf[0] = str1[len1-1];
        string ss(buf);
        if (tmp.empty()) {
            s.insert(ss);
        } else {
            for (auto x: tmp) {
                s.insert(x+ss);
            }
        }
    }
    return s;
}

// 重置动态规划用的二维数组，数组len1+1行，len2+1列
void clear(int len1, int len2)
{
    // 第一行与第一列都是0，分别表示:
    // str1的前0个字符与str2的前0~len2字符的LCS都为0
    // str2的前0个字符与str1的前0~len1字符的LCS都为0
    for (int i = 0; i < len1; ++i)
    {
        dp[i][0] = 0; // 第一列都是0
    }
    for (int j = 0; j < len1; ++j)
    {
        dp[0][j] = 0; // 第一行都是0
    }
    // 其余位置初始化为-1，表示还未设置
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

    // 递归求
    clear(len1, len2);
    cout << LCS(str1, len1, str2, len2) << endl;
    set<string> s = get_all_sequence(len1, len2);
    cout<<"size: "<<s.size()<<endl;
    for (auto x: s){
        cout<<x<<endl;
    }
    cout << endl;

    // 非递归求
    clear(len1, len2);
    cout << LCS2(str1, len1, str2, len2) << endl;
    s = get_all_sequence(len1, len2);
    cout<<"size: "<<s.size()<<endl;
    for (auto x: s){
        cout<<x<<endl;
    }
    cout << endl;

    return 0;
}