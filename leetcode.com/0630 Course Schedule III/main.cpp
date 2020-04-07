#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

// greedy
// class Solution {
//  public:
//   int scheduleCourse(vector<vector<int>>& courses) {
//     sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
//       return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
//     });
//     multiset<int> s;
//     int res = 0;
//     int endTime = 0;
//     for (auto& course : courses) {
//       if (endTime + course[0] <= course[1]) {
//         s.insert(course[0]);
//         ++res;
//         endTime += course[0];
//       } else if (!s.empty()) {
//         auto it = prev(s.end());
//         if (course[0] < *it && endTime + (course[0] - *it) <= course[1]) {
//           endTime += course[0] - *it;
//           s.erase(it);
//           s.insert(course[0]);
//         }
//       }
//     }
//     return res;
//   }
// };

// greedy
// heap (priority queue)
class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
      return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    });
    priority_queue<int> q;
    int res = 0;
    int endTime = 0;
    for (auto& course : courses) {
      if (endTime + course[0] <= course[1]) {
        q.push(course[0]);
        ++res;
        endTime += course[0];
      } else if (!q.empty()) {
        if (course[0] < q.top() && endTime + (course[0] - q.top()) <= course[1]) {
          endTime += course[0] - q.top();
          q.pop();
          q.push(course[0]);
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> courses = {{100, 2}, {32, 50}};
  courses = {{7, 17}, {3, 12}, {10, 20}, {9, 10}, {5, 20}, {10, 19}, {4, 18}};
  cout << s.scheduleCourse(courses) << endl;
  return 0;
}
