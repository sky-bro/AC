#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   * Mask Personal Information
   * @param S either an email address or a phone number
   * email: name@name.name, name: lower or upper case letters with len >= 2
   * phone number: consists of only digits 0-9 or characters from {'+', '-',
   * '(', ')', ' '}
   * @returns "mask" of the information provided
   */
  string maskPII(string S) {
    int n = S.length();
    string res = "";
    if (isalpha(S[n - 1])) {
      for (char &c : S) c = tolower(c);
      // a@b.c
      int len = 0;
      while (S[len + 2] != '@') ++len;
      return S.replace(1, len, "*****");
    } else {
      vector<int> nums;
      for (char c : S) {
        if (isdigit(c)) {
          nums.push_back(c);
        }
      }
      n = nums.size();
      if (n > 10) {
        res.push_back('+');
        for (int i = 10; i < n; ++i) {
          res.push_back('*');
        }
        res.push_back('-');
      }
      res += "***-***-";
      res.push_back(nums[n - 4]);
      res.push_back(nums[n - 3]);
      res.push_back(nums[n - 2]);
      res.push_back(nums[n - 1]);
    }
    return res;
  }
};
