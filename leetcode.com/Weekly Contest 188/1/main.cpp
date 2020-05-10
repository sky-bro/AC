#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int i = 0, r = target.size();

        for (int c = 1; i < r; ++c) {
          res.push_back("Push");
          if (c == target[i]) ++i;
          else res.push_back("Pop");
        }
        return res;
    }
};
