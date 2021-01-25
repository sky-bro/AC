#include <iostream>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
  ll m, n, a;
  cin >> m >> n >> a;
  cout << ((m + a - 1) / a) * ((n + a - 1) / a) << endl;
  return 0;
}
