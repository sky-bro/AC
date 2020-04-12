#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// using heap is simple
// just simulate the process

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (!pq.empty()) {
          int a= pq.top();
          pq.pop();
          if (pq.empty()) return a;
          int b= pq.top();pq.pop();
          if (a>b) {
            pq.push(a-b);
          } else if(a<b) {
            pq.push(b-a);
          }
        }
        return 0;
    }
};