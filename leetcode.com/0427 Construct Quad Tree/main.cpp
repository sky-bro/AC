#include <iostream>
#include <vector>

using namespace std;

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
 private:
  int n;
  uint64_t mask;

  Node* helper(vector<uint64_t>& grid, int i1, int j1, int i2, int j2) {
    int len = i2 - i1;
    // isleaf?
    bool isLeaf = true;
    bool isOne = (grid[i1] >> (n - j2)) & 1;
    for (int j = j2 - 1; j > j1; --j) {
      if (isOne != ((grid[i1] >> (n - j)) & 1)) {
        isLeaf = false;
        break;
      }
    }
    if (isLeaf) {
      uint64_t num = (((grid[i1] << j1) & mask) >> j1) >> (n - j2);
      for (int i = i1 + 1; i < i2; ++i) {
        if (num != (((grid[i] << j1) & mask) >> j1) >> (n - j2)) {
          isLeaf = false;
          break;
        }
      }
    }

    if (isLeaf) {
      return new Node(isOne, true);
    } else {
      Node* root = new Node(true, false);
      root->topLeft = helper(grid, i1, j1, i1 + len / 2, j1 + len / 2);
      root->topRight = helper(grid, i1, j1 + len / 2, i1 + len / 2, j2);
      root->bottomLeft = helper(grid, i1 + len / 2, j1, i2, j1 + len / 2);
      root->bottomRight = helper(grid, i1 + len / 2, j1 + len / 2, i2, j2);
      return root;
    }
  }

 public:
  Node* construct(vector<vector<int>>& grid) {
    n = grid.size();
    mask = 0;
    for (int i = 0; i < n; ++i) {
      mask <<= 1;
      ++mask;
    }
    vector<uint64_t> new_grid(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        new_grid[i] = (new_grid[i] << 1) + grid[i][j];
      }
    }

    Node* res = helper(new_grid, 0, 0, n, n);
    return res;
  }
};

int main(int argc, char const* argv[]) {
  // [[0,1],[1,0]]
  // [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
  // [[1,1],[1,1]]
  // [[0]]
  // [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
  Solution s;
  vector<vector<int>> grid = {{0, 1}, {1, 0}};
  grid = {{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
          {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};

  grid = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0},
          {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
          {0, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1}};

  grid = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
          {1, 1, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0},
          {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
          {0, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1}};
  s.construct(grid);
  return 0;
}
