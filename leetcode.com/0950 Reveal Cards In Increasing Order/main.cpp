#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    sort(deck.begin(), deck.end());
    vector<int> res(n);
    // 2 3 5 7 11 13 17
    // [x x x x x x x]
    // [2 x 3 x 5 x 7]
    queue<int> q;  // index
    for (int i = 0; i < n; ++i) q.push(i);
    int j = -1;
    while (1) {
      int i = q.front();
      q.pop();
      res[i] = deck[++j];
      if (q.empty()) break;
      i = q.front();
      q.pop();
      q.push(i);
    }
    return res;
  }
};
