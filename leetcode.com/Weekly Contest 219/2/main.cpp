#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

static int x = []() {ios::sync_with_stdio(false); cin.tie(0); return 0; } ();
typedef long long ll;

class Solution {
public:
    int minPartitions(string n) {
        return (*max_element(n.begin(), n.end())) - '0';
    }
};
