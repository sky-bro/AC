#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

class Parser {
 private:
  Parser *A;
  string B;
  int reps;
  ull len;

 public:
  Parser(const string &S, int n);
  ~Parser();
  ull length() { return len; }
  string operator[](int k) {
    k %= len;
    ull alen = len - B.length();
    if (alen > k) return (*A)[k];
    k -= alen;
    return B.substr(k, 1);
  }
};

Parser::Parser(const string &S, int n) {
  A = nullptr;
  if (S[n - 1] <= '9' && S[n - 1] >= '2')
    reps = S[--n] - '0';
  else
    reps = 1;
  int i = n - 1;
  for (; i >= 0; --i) {
    if (S[i] <= '9' && S[i] >= '2') break;
  }
  B = S.substr(i + 1, n - i - 1);
  len = n - i - 1;
  n = i + 1;
  if (n > 0) {
    A = new Parser(S, n);
    len += A->len * A->reps;
  }
}

Parser::~Parser() {
  if (A) delete A;
}

class Solution {
 public:
  string decodeAtIndex(string S, int K) { return Parser(S, S.length())[K - 1]; }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string S;
  int K;
  while (cin >> S >> K) {
    cout << s.decodeAtIndex(S, K) << endl;
  }
  return 0;
}
