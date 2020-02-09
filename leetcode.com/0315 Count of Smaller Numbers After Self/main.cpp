#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76657/3-ways-(Segment-Tree-Binary-Indexed-Tree-Binary-Search-Tree)-clean-python-code

struct Node
{
    int val;
    int idx;
    int cnt;
    Node(int val, int idx): val(val), idx(idx), cnt(0) {}
    bool operator<(const Node& other) {
        return val < other.val;
    }
};


class Solution {
private:
    void merge(vector<Node>& nodes, int left, int mid, int right) {
        vector<Node> aux_arr;
        int i = right, j = mid;
        for (; i > mid && j >= left;) {
            if (nodes[i] < nodes[j]) {
                nodes[j].cnt += i - mid;
                aux_arr.push_back(nodes[j--]);
            } else {
                aux_arr.push_back(nodes[i--]);
            }
        }

        for (; i > mid; ) aux_arr.push_back(nodes[i--]);
        for (; j >= left; ) aux_arr.push_back(nodes[j--]);

        for (Node &node: aux_arr) {
            nodes[right--] = node;
        }
    }

    void merge_sort(vector<Node>& nodes, int left, int right) {
        if (left >= right) return;
        int mid = left + (right-left)/2;
        merge_sort(nodes, left, mid);
        merge_sort(nodes, mid+1, right);
        merge(nodes, left, mid, right);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<Node> nodes;
        for (int i = 0; i < n; ++i) {
            nodes.push_back(Node(nums[i], i));
        }

        merge_sort(nodes, 0, n-1);

        vector<int> result(n);
        for (Node &node: nodes) {
            result[node.idx] = node.cnt;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {5,2,6,1};
    s.countSmaller(nums);
    return 0;
}
