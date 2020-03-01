#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  // zero one two three four five six seven eight nine
  // a:
  // b:
  // c:
  // d:
  // e:
  // f: (2) 4 5
  // g: (1) 8
  // h: (2) 3 8
  // i:
  // j:
  // k:
  // l:
  // m:
  // n: (4) 1 7 9 9
  // o: (4) 0 1 2 4
  // p:
  // q:
  // r: (3) 0 3 4
  // s: (2) 6 7
  // t: (3) 2 3 8
  // u: (1) 4
  // v: (2) 5 7
  // w: (1) 2
  // x: (1) 6
  // y:
  // z: (1) 0

  string originalDigits(string s) {
    int cnt[26]{};
    int res[10]{};
    for (char c : s) {
      cnt[c - 'a']++;
    }
    // for (int i = 0; i < 26; ++i) {
    //   cout << char('a' + i) << ": " << cnt[i] << endl;
    // }
    res[0] = cnt['z' - 'a'];

    res[2] = cnt['w' - 'a'];

    res[4] = cnt['u' - 'a'];

    res[1] = cnt['o' - 'a'] - res[0] - res[2] - res[4];

    res[6] = cnt['x' - 'a'];
    res[7] = cnt['s' - 'a'] - res[6];

    res[5] = cnt['v' - 'a'] - res[7];

    res[8] = cnt['g' - 'a'];

    res[3] = cnt['h' - 'a'] - res[8];

    res[9] = (cnt['n' - 'a'] - res[1] - res[7]) / 2;
    string str = "";
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < res[i]; ++j) {
        str.push_back('0' + i);
      }
    }
    return str;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str = "zeroonetwothreefourfivesixseveneightnine";
  cout << s.originalDigits(str) << endl;
  return 0;
}
