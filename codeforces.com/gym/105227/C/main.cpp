#include <bits/stdc++.h>

using namespace std;

int MAX = 1e9;
vector<int> A;

void init()
{
    int n = 1;
    A.push_back(2);
    while (true)
    {
        long next = A.back() + 3 * n + 2;
        if (next > MAX)
        {
            break;
        }
        A.push_back(next);
        ++n;
    }
}

int solve(int x)
{
    // A1 = 2
    // A2 = A1 + 3*1 + 2
    // A3 = A2 + 3*2 + 2
    // An = 3n(n-1)/2 + 2*n
    int count = 0;
    auto left = A.begin();
    auto right = A.end();
    while (x >= A[0])
    {
        ++count;
        auto tmp = upper_bound(left, right, x);
        if (tmp == A.end()) {
            tmp = right - 1;
        } else {
            --tmp;
        }
        x -= *tmp;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    init();
    while (n--)
    {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}
