#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    int freq[128]{};
    for (char c : s) freq[c]++;
    sort(s.begin(), s.end(), [&freq](char a, char b) {
      return freq[a] == freq[b] ? a < b : freq[a] > freq[b];
    });
    return s;
  }
};