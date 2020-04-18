#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int total = (1<<(n-1));
        if (k > total*3) return "";
        char pre;
        string res ="";
        if ( k <= total) {
          pre = 'a';
        } else if (k <= total*2) {
          pre = 'b';
          k -= total;
        } else {
          pre = 'c';
          k -= 2*total;
        }
        res.push_back(pre);
        for (int i = 1; i < n; ++i) {
          total /= 2;
          if (pre == 'a') {
            if (k <= total) {
              pre = 'b';
            } else {
              k -= total;
              pre = 'c';
            }
          } else if (pre == 'b') {
            if (k <= total) {
              pre = 'a';
            } else {
              k -= total;
              pre = 'c';
            }
          } else {
            if (k <= total) {
              pre = 'a';
            } else {
              k -= total;
              pre = 'b';
            }
          }
          res.push_back(pre);
        }
        return res;
    }
};