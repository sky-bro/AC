#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
      int n = S.length();
      vector<int> cnt(26);
      for (char c: S) cnt[c-'a']++;
      auto cmp = [&](int i, int j) {
        return cnt[i] < cnt[j];
      };
      priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
      for (int i = 0; i < 26; ++i) if (cnt[i]) pq.push(i);
      int pre = pq.top(); pq.pop();
      if (cnt[pre]*2-1 > n) return "";
      string res = "";
      res.push_back(pre+'a');
      --cnt[pre];
      for (int i = 1; i < n; ++i) {
        int cur = pq.top(); pq.pop();
        --cnt[cur];
        res.push_back(cur+'a');
        pq.push(pre);
        pre = cur;
      }
      return res;
    }
};

int main(int argc, char const *argv[])
{
  Solution s;
  string S;
  while (cin>>S) {
    cout<<s.reorganizeString(S)<<endl;
  }
  return 0;
}
