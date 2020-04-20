#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for (int i = str.length()-1; i >= 0; --i) {
          if (str[i] <= 'Z' && str[i] >= 'A') str[i] += 'a' - 'A';
        }
        return str;
    }
};
