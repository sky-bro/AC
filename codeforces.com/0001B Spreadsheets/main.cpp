#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

string toA(string &&a) {
  int c = stoi(a);
  string C = "";
  while (c) {
    char chr = c % 26;
    chr = (chr == 0) ? 'Z' : (chr - 1 + 'A');
    C.push_back(chr);
    c /= 26;
    if (chr == 'Z') --c;
  }
  reverse(C.begin(), C.end());
  return C;
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int c;
    if (s[0] == 'R' && isdigit(s[1]) && (c = s.find('C')) != -1) {
      // R23C55
      string &&C = toA(s.substr(c + 1));
      cout << C << s.substr(1, c - 1) << endl;
    } else {
      // BC23
      c = 0;
      int i = 0;
      for (; isalpha(s[i]); ++i) {
        c = c * 26 + s[i] - 'A' + 1;
      }
      cout << "R" << s.substr(i) << "C" << to_string(c) << endl;
    }
  }
  return 0;
}
