#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Tweet {
  int tweetId;
  int globalId;
  bool operator<(const Tweet& b) { return globalId < b.globalId; }
  Tweet(int tid, int gid) : tweetId(tid), globalId(gid) {}
};

struct Pair {
  vector<Tweet>::reverse_iterator first;
  vector<Tweet>::reverse_iterator second;
  Pair(vector<Tweet>::reverse_iterator a, vector<Tweet>::reverse_iterator b)
      : first(a), second(b) {}
};

bool operator<(const Pair& a, const Pair& b) { return *a.first < *b.first; }

class Twitter {
 private:
  unordered_map<int, vector<Tweet>> tweets;
  unordered_map<int, unordered_set<int>> relations;
  int globalId = 0;

 public:
  /** Initialize your data structure here. */
  Twitter() { tweets.clear(); }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back(Tweet(tweetId, globalId++));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    priority_queue<Pair> q;
    if (!tweets[userId].empty()) {
      q.push(Pair(tweets[userId].rbegin(), tweets[userId].rend()));
      //   q.push(make_pair(tweets[userId].begin(), tweets[userId].end()));
    }
    for (auto followee : relations[userId]) {
      if (!tweets[followee].empty()) {
        q.push(Pair(tweets[followee].rbegin(), tweets[followee].rend()));
        // q.push(make_pair(tweets[followee].begin(), tweets[followee].end()));
      }
    }
    vector<int> res;
    while (!q.empty() && res.size() < 10) {
      auto p = q.top();
      q.pop();
      res.push_back((p.first)->tweetId);
      p.first++;
      if (p.first != p.second) {
        q.push(p);
      }
    }
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    if (followeeId != followerId) {
      relations[followerId].insert(followeeId);
    }
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    relations[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main(int argc, char const* argv[]) {
  Twitter twitter;
  twitter.postTweet(1, 5);
  twitter.postTweet(1, 3);
  twitter.postTweet(1, 101);
  twitter.postTweet(1, 13);
  twitter.postTweet(1, 10);
  twitter.postTweet(1, 2);
  twitter.postTweet(1, 94);
  twitter.postTweet(1, 505);
  twitter.postTweet(1, 333);
  twitter.getNewsFeed(1);
  return 0;
}
