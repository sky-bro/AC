#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    char c = *max_element(s.begin(), s.end());
    cout << string(count(s.begin(), s.end(), c), c) << endl;
    return 0;
}
