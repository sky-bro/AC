#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char seq[81];
    cin >> seq;
    int cur_score = 0, total_score = 0;
    for (int i = 0;; ++i)
    {
        if (seq[i] == 'O')
        {
            total_score += ++cur_score;
        }
        else if (seq[i] == 'X')
        {
            cur_score = 0;
        }
        else
            break;
    }
    cout << total_score << endl;
    return 0;
}
