#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class TweetCounts {
private:
    unordered_map<string, vector<int>> map;
    int toSeconds[3] = {60, 3600, 86400};
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        if (map.find(tweetName) != map.end()) {
            auto &vi = map[tweetName];
            auto it = lower_bound(vi.begin(), vi.end(), time);
            if (it == vi.end()) vi.push_back(time);
            else {
                vi.insert(it, time);
            }

        } else {
            map[tweetName] = {time};
        }
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if (map.find(tweetName) == map.end()) return {};
        vector<int> result;
        auto &vi = map[tweetName];
        int type;
        if (freq[0] == 'm') { // minute
            type = 0;
        } else if (freq[0] == 'h') { // hour
            type = 1;
        } else { // day
            type = 2;
            
        }
        auto left = vi.begin();
        for (int i = startTime; i <= endTime; i += toSeconds[type]) {
            auto it = lower_bound(left, vi.end(), i);
            // if (it == vi.end()) break;
            auto right = upper_bound(it, vi.end(), min(endTime+1, i+toSeconds[type]-1));
            left = right;
            result.push_back(right-it);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    TweetCounts tweetCounts;
    tweetCounts.recordTweet("tweet3", 0);
    tweetCounts.recordTweet("tweet3", 60);
    tweetCounts.recordTweet("tweet3", 10);
    tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]. The frequency is per minute (60 seconds), so there is one interval of time: 1) [0, 60> - > 2 tweets.
    tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2, 1]. The frequency is per minute (60 seconds), so there are two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 1 tweet.
    tweetCounts.recordTweet("tweet3", 120);                            // All tweets correspond to "tweet3" with recorded times at 0, 10, 60 and 120.
    tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  
    return 0;
}


/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */