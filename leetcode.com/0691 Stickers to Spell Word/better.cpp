#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// fastest
// BFS
// beats 100% @time&space
// leetcode discuss: [C++] 16ms BFS, beats 100% @time&space, commented
// https://leetcode.com/problems/stickers-to-spell-word/discuss/578394/C%2B%2B-16ms-BFS-beats-100-%40timeandspace-commented
class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    size_t m = stickers.size(), n = target.size();
    vector<vector<int> > map{m, vector<int>(26)};
    for (int i = 0; i < m; i++)
      for (char c : stickers[i]) map[i][c - 'a']++;

    // check if cur_target has been visited
    unordered_set<int> vis;

    // BFS
    // store the bit representation of target string
    queue<int> q;
    // target at the beginning: all bits set to 1
    q.push((1 << n) - 1);
    int level = 0;
    while (!q.empty()) {
      ++level;
      for (int sz = q.size(); sz > 0; --sz) {
        int cur_target = q.front();
        q.pop();
        // check if cur_target has been visited
        if (vis.count(cur_target))
          continue;
        else
          vis.insert(cur_target);
        // the starting point from the right that need to be eliminated
        // because we always try to remove the right most char first (heuristic,
        // see below)
        int start = 0;
        while (start < n) {
          if ((cur_target >> start) & 1)
            break;
          else
            ++start;
        }

        for (int i = 0; i < m; ++i) {  // try all stickers
          // heuristic (this is the key speedup, we try stickers with char
          // target[n-1-start] first so we always can remove the right most
          // char in cur_target)
          if (map[i][target[n - 1 - start] - 'a'] == 0) continue;
          int next_target = cur_target;
          // try every char in stickers[i], delete it from cur_target
          for (char c : stickers[i]) {
            for (int r = start; r < n; r++) {  // delete from right to left
              if (target[n - 1 - r] == c && ((next_target >> r) & 1)) {
                next_target ^= (1 << r);
                break;
              }
            }
          }
          if (next_target == 0) return level;
          q.push(next_target);
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> stickers = {"with", "example", "science"};
  string target = "thehat";
  cout << s.minStickers(stickers, target) << endl;
  return 0;
}
