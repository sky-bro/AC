#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class FreqStack {
 private:
  unordered_map<int, int> freq;
  priority_queue<array<int, 3>> pq;
  int id;
  // (freq, ord, num)
 public:
  FreqStack() : id(INT32_MIN) {}

  void push(int x) { pq.push({freq[x]++, id++, x}); }

  int pop() {
    auto a = pq.top();
    pq.pop();
    --freq[a[2]];
    return a[2];
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
