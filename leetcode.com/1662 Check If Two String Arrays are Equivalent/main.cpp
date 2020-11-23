#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

char arr1[1010];
char arr2[1010];
class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int n1 = 0;
    int n2 = 0;
    for (string& word : word1) {
      for (char c : word) arr1[n1++] = c;
    }
    for (string& word : word2) {
      for (char c : word) arr2[n2++] = c;
    }
    return n1 == n2 && !strncmp(arr1, arr2, n1);
  }
};
