#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    vector<bool> visited(n);
    for (int i = 0; i < n; ++i) {
      if (leftChild[i] != -1) {
        if (visited[leftChild[i]])
          return false;
        else
          visited[leftChild[i]] = true;
      }

      if (rightChild[i] != -1) {
        if (visited[rightChild[i]])
          return false;
        else
          visited[rightChild[i]] = true;
      }
    }

    int root_cnt = 0;
    for (bool b : visited) {
      if (!b) ++root_cnt;
      if (root_cnt > 1) return false;
    }
    return root_cnt == 1;
  }
};