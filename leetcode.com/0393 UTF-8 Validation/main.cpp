#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int count_bytes(int first_byte) {
    int mask = 1 << 7;
    int res = 0;
    for (int i = 0; i < 4; ++i) {
      if (first_byte & mask) {
        ++res;
      } else {
        break;
      }
      mask >>= 1;
    }

    // res could only be 0, 2, 3, 4
    if ((first_byte & mask) || res == 1) return 0;
    return res ? res : 1;
  }

 public:
  bool validUtf8(vector<int>& data) {
    int n = data.size();
    for (int i = 0; i < n;) {
      int bytes_cnt = count_bytes(data[i]);
      if (bytes_cnt == 0 || i + bytes_cnt > n) return false;
      i += bytes_cnt;
      for (int j = i - bytes_cnt + 1; j < i; ++j) {
        if ((data[j] & 0xC0) != 0x80) return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution sol;
  vector<int> data = {197, 130, 1};  // true
  cout << sol.validUtf8(data) << endl;
  data = {235, 140, 4};  // false
  cout << sol.validUtf8(data) << endl;
  return 0;
}
