#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class TopVotedCandidate {
 private:
  vector<pair<int, int>> v;

 public:
  TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    int n = persons.size();
    // (cnt, i, ID)
    unordered_map<int, int> cnts;
    priority_queue<array<int, 3>> pq;
    for (int i = 0; i < n; ++i) {
      int t = times[i];
      int id = persons[i];
      pq.push({++cnts[id], i, id});
      v.emplace_back(t, pq.top()[2]);
    }
  }

  int q(int t) {
    auto it = upper_bound(v.begin(), v.end(), make_pair(t, INT32_MAX));
    return prev(it)->second;
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

int main(int argc, char const* argv[]) {
  vector<int> persons = {0, 1, 1, 0, 0, 1, 0},
              times = {0, 5, 10, 15, 20, 25, 30},
              queries = {3, 12, 25, 15, 24, 8};
  TopVotedCandidate t(persons, times);
  for (int q : queries) {
    cout << t.q(q) << endl;
  }
  return 0;
}
