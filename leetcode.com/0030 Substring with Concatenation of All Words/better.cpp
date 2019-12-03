// https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/373766/c%2B%2B-Solution-32ms-based-on-sliding-window
#include <iostream>
#include <vector>
#include <unordered_map> // 效率比map高，不需要排序

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
		if (words.empty())return result;

		// counts用来
		// record用来
		unordered_map<string, int> counts, record;
		for (string word : words) {
			// 同一个word可能出现多次
			counts[word]++;
		}

		// 单词长度一样，都是len
		int len = words[0].size(), num = words.size(), sl = s.size();
		// 
		for (int i = 0; i < len; ++i) {
			// left存放一次完整匹配words的开始位置
			int left = i, sum = 0;
            record.clear();
			for (int j = i; j <= sl - len; j+=len) {
				string word = s.substr(j, len);

				// 如果是某个模式串
				if (counts.count(word)) {
					record[word]++;
                    sum++;

                    while (record[word] > counts[word])
                    {
                        //remove the most left word
                        record[s.substr(left, len)]--;
                        left += len;
                        sum--;
                    }
					if (sum == num) 
						result.push_back(left);
				}
				// 如果不是模式串
				else
				{
					record.clear();
					sum = 0;
					left = j + len;
				}
			}
		}
		return result;
    }
};