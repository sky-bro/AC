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

		// counts用来记录每个单词 应该有的次数
		// record用来记录当前连续匹配到的各个单词的个数
		unordered_map<string, int> counts, record;
		for (string word : words) {
			// 同一个word可能出现多次，记录应该有的次数
			counts[word]++;
		}

		// 单词长度一样，都是len
		int len = words[0].size(), num = words.size(), sl = s.size();

		// 单词的开始位置为i (mod len)
		for (int i = 0; i < len; ++i) {
			// left存放一次完整匹配words的开始位置
			// sum记录连续匹配到的单词数目，等于num时说明找到一个答案
			int left = i, sum = 0;
			// 开始时record应该为空，还没有匹配任何单词；清除上一次可能残留的record
            record.clear();

			// 依次查看下一个len长的单词
			for (int j = i; j <= sl - len; j+=len) {
				// 下一个len长的单词
				string word = s.substr(j, len);

				// 这里相当于直接用hash查找判断是否匹配上
				// 如果是某个模式串
				// counts.find(word)
				if (counts.find(word) != counts.end()) {
					// 记录+1,总数也+1
					record[word]++;
                    sum++;

					// 检查，刚才加进来的这个单词可能超过了需要的个数
					// 不断删除最左边的匹配,直到该单词记录数和需要的相等
                    while (record[word] > counts[word])
                    {
                        //remove the most left word
                        record[s.substr(left, len)]--;
						// 匹配开始于left，现在向后调整一个len长度
                        left += len;
                        sum--;
                    }
					// 一旦sum和num相等,说明我们匹配到所有的模式串了,保存left
					if (sum == num)
						result.push_back(left);
				}
				// 如果s[j,j+len)不是模式串
				else
				{
					// 一切从j+len再开始匹配 -- left设置为j+len
					record.clear();
					sum = 0;
					left = j + len;
				}
			}
		}
		return result;
    }
};