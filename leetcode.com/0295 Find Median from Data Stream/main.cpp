#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MedianFinder {
private:
    vector<int> min_heap, max_heap;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (min_heap.size() != max_heap.size()) {
            // 奇数
            if (min_heap.size() > max_heap.size()) {
                if (num > min_heap[0]) {
                    int tmp = min_heap[0];
                    pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                    min_heap[min_heap.size()-1] = num;
                    push_heap(min_heap.begin(), min_heap.end(), greater<int>());

                    max_heap.push_back(tmp);
                    push_heap(max_heap.begin(), max_heap.end());
                } else {
                    max_heap.push_back(num);
                    push_heap(max_heap.begin(), max_heap.end());
                }
            } else {
                if (num < max_heap[0]) {
                    int tmp = max_heap[0];
                    pop_heap(max_heap.begin(), max_heap.end());
                    max_heap[max_heap.size()-1] = num;
                    push_heap(max_heap.begin(), max_heap.end());

                    min_heap.push_back(tmp);
                    push_heap(min_heap.begin(), min_heap.end(), greater<int>());
                } else {
                    min_heap.push_back(num);
                    push_heap(min_heap.begin(), min_heap.end(), greater<int>());
                }
            }
        } else {
            // 偶数
            if (max_heap.size() > 0 && num <= max_heap[0]) {
                max_heap.push_back(num);
                push_heap(max_heap.begin(), max_heap.end());
            } else {
                min_heap.push_back(num);
                push_heap(min_heap.begin(), min_heap.end(), greater<int>());
            }
        }
    }
    
    double findMedian() {
        if (min_heap.size() == max_heap.size()) {
            if (min_heap.empty()) return 0;
            return (double(min_heap[0]) + double(max_heap[0])) / 2;
        } else {
            if (min_heap.size() > max_heap.size()) {
                return min_heap[0];
            } else {
                return max_heap[0];
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */