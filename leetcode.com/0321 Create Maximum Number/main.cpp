#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
private:
    int n1, n2, k;
    vector<int> result;
    void bfs(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0;
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        while (cnt != k) {
            // vector<pair<int, int>> next_q;
            set<pair<int, int>> next_q;
            int cur_max = -1;
            for (int sz = q.size(); sz > 0; --sz) {
                auto p = q.front(); q.pop();
                int idx1 = p.first, idx2 = p.second;
                int max1 = -1, max2 = -1, max_idx1, max_idx2;
                for (int i = idx1; i < n1 && n1 - i + n2 - idx2 >= k - cnt; ++i) {
                    if (nums1[i] > max1) {
                        max1 = nums1[i];
                        max_idx1 = i;
                    }
                }

                for (int i = idx2; i < n2 && n2 - i + n1 - idx1 >= k - cnt; ++i) {
                    if (nums2[i] > max2) {
                        max2 = nums2[i];
                        max_idx2 = i;
                    }
                }

                if (max1 > max2) {
                    if (max1 > cur_max) {
                        next_q.clear();
                        cur_max = max1;
                        auto p = make_pair(max_idx1+1, idx2);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                    } else if (max1 == cur_max) {
                        auto p = make_pair(max_idx1+1, idx2);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                    }
                } else if (max1 < max2) {
                    if (max2 > cur_max) {
                        next_q.clear();
                        cur_max = max2;
                        auto p = make_pair(idx1, max_idx2+1);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                    } else if (max2 == cur_max) {
                        auto p = make_pair(idx1, max_idx2+1);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                    }
                } else {
                    if (max1 > cur_max) {
                        next_q.clear();
                        cur_max = max1;
                        auto p = make_pair(max_idx1+1, idx2);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                        p = make_pair(idx1, max_idx2+1);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                    } else if (max1 == cur_max) {
                        auto p = make_pair(max_idx1+1, idx2);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                        p = make_pair(idx1, max_idx2+1);
                        if (next_q.find(p) == next_q.end())
                            next_q.insert(p);
                    }
                }
            }
            result[cnt++] = cur_max;
            for (auto &p: next_q) {
                q.push(p);
            }
        }

    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        n1 = nums1.size();
        n2 = nums2.size();
        this->k = k;
        result.clear();
        result.resize(k, -1);
        bfs(nums1, nums2);
        return result;

    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<int> nums1 = {6, 7};
    vector<int> nums2 = {6, 0, 4};
    int k = 5; // 6 7 6 0 4

    s.maxNumber(nums1, nums2, k);

    nums2 = {3, 9};
    nums1 = {8, 9};
    k = 3; // 9 8 9

    // nums1 = {7,8,3,6,8,2,8,2,3,1,4,7,1,0,7,3,6,1,0,4,2,4,1,7,8,7};
    // nums2 = {3,2,4};
    // k = 29;

    // nums1 = {1,6,5,4,7,3,9,5,3,7,8,4,1,1,4};
    // nums2 = {4,3,1,3,5,9};
    // k = 21;

    // nums1 = {5,0,2,1,0,1,0,3,9,1,2,8,0,9,8,1,4,7,3};
    // nums2 = {7,6,7,1,0,1,0,5,6,0,5,0};
    // k = 31;

    s.maxNumber(nums1, nums2, k);
    return 0;
}
