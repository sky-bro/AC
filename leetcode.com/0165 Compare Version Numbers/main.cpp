#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int len1 = 0, len2 = 0;
        char *buf1 = new char[version1.length() + 1];
        char *buf2 = new char[version2.length() + 1];
        strcpy(buf1, version1.c_str());
        strcpy(buf2, version2.c_str());
        char *s = strsep(&buf1, ".");
        while (s) {
            v1.push_back(atoi(s));
            s = strsep(&buf1, ".");
            ++len1;
        }

        s = strsep(&buf2, ".");
        while (s) {
            v2.push_back(atoi(s));
            s = strsep(&buf2, ".");
            ++len2;
        }

        for (; len1 > 0 && !v1[len1-1]; v1.pop_back(), --len1);
        for (; len2 > 0 && !v2[len2-1]; v2.pop_back(), --len2);

        int idx = 0, min_len = min(len1, len2);
        for (; idx < min_len; ++idx) {
            if (v1[idx] < v2[idx]) return -1;
            else if (v1[idx] > v2[idx]) return 1;
        }

        if (len1 < len2) return -1;
        else if (len1 > len2) return 1;
        else return 0;
    }
};