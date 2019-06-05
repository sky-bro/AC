/**
 * 输入四个整数：p, e, i 和 d。分别表示体力、情感和智力高峰出现日子。
 * 每隔23，28，33天出现
 * d是给定日子。
 * 从给定日子起，下一次三个高峰同一天的日子
 * 
 */

#include <iostream>
using namespace std;
int main()
{
    int p, e, i, d;
    cin >> p >> e >> i >> d;
    int res = 1;
    for (;; ++res)
    {
        if ((p - (d + res)) % 23 == 0)
        {
            for (;; res += 23)
            {
                if ((e - (d + res)) % 28 == 0)
                {
                    for (;; res += 23 * 28)
                    {
                        if ((i - (d + res) % 33) == 0)
                        {
                            cout << res << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
}