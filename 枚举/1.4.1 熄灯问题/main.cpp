#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char in[5];
char tmp[5];
char out[5];

int GetBit(char c, int i)
{
    return (c >> i) & 1;
}

void SetBit(char &c, int i, int v)
{
    if (v)
    {
        c |= (1 << i);
    }
    else
    {
        c &= ~(1 << i);
    }
}

void FlipBit(char &c, int i)
{
    c ^= (1 << i);
}

void cal(int t)
{
    cout << "PUZZLE #" << t << endl;
    for (int n = 0; n < 64; ++n)
    {
        memcpy(tmp, in, sizeof(in));
        int switches = n;
        for (int i = 0; i < 5; ++i)
        {
            out[i] = switches;
            for (int j = 0; j < 6; ++j)
            {
                if (GetBit(switches, j))
                {
                    if (j > 0)
                    {
                        FlipBit(tmp[i], j - 1);
                    }
                    FlipBit(tmp[i], j);
                    if (j < 5)
                    {
                        FlipBit(tmp[i], j + 1);
                    }
                }
            }
            if (i < 4)
            {
                tmp[i + 1] ^= switches;
            }
            switches = tmp[i];
        }
        if (!tmp[4])
        {
            // cout <<"TMP"<<(int)tmp[4]<<endl;
            for (int i = 0; i < 5; i++)
            {
                for (int j = 5; j >= 0; --j)
                {
                    cout << GetBit(out[i], j);
                    if (j > 0)
                        cout << " ";
                }
                // if (i < 4)
                    cout << endl;
            }
            break;
        }
    }
}

int main()
{
    int n, tmp;
    cin >> n;
    for (int t = 1; t <= n; ++t)
    {
        for (int i = 0; i < 5; ++i)
        {
            int row = 0;
            for (int j = 0; j < 6; ++j)
            {
                cin >> tmp;
                row = row * 2 + tmp;
            }
            in[i] = row;
            // cout <<"row"<< row;
        }
        cal(t);
    }
    return 0;
}