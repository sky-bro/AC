#include <iostream>
#include <random>
#include <regex>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    while (!url2code.count(longUrl)) {
      string code = "";
      for (int i = 0; i < 6; i++)
        code.push_back(charset[rd() % charset.size()]);
      if (!code2url.count(code)) {
        url2code.emplace(longUrl, code);
        code2url.emplace(code, longUrl);
      }
    }
    return "http://tinyurl.com/" + url2code[longUrl];
  }
  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    // string pattern("http://tinyurl.com/(\\w{6})/?");
    string code = shortUrl.substr(19);
    auto it = code2url.find(code);
    return it == code2url.end() ? "" : it->second;
  }

 private:
  const string charset =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  unordered_map<string, string> url2code, code2url;
  random_device rd;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));