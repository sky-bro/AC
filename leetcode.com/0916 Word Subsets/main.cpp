#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  unordered_map<char, int> cnts;
  inline bool chk(const string &a) {
    unordered_map<char, int> t;
    for (char c : a) ++t[c];
    for (auto &p : cnts) {
      if (p.second > t[p.first]) return false;
    }
    return true;
  }

 public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
    cnts.clear();
    vector<string> res;
    for (const string &b : B) {
      unordered_map<char, int> t;
      for (char c : b) ++t[c];
      for (auto &p : t) {
        cnts[p.first] = max(cnts[p.first], p.second);
      }
    }
    for (const string &a : A) {
      if (chk(a)) res.push_back(a);
    }
    return res;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int N = 10000;
  vector<bool> primes(N, true);
  vector<int> res;
  for (int i = 2; i < N && res.size() != 26; ++i) {
    if (primes[i] == false) continue;
    res.push_back(i);
    for (int j = i * i; j < N; j += i) primes[j] = false;
  }
  printArr(res);
  return 0;
}
