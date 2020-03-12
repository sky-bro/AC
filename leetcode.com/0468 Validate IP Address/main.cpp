#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Solution {
 public:
  string validIPAddress(string IP) {
    regex IPv4_pattern("^((\\d|[1-9]\\d|1\\d\\d|2([0-4]\\d|5[0-5]))\\.){4}$");
    regex IPv6_pattern("^([\\da-fA-F]{1,4}:){8}$");
    if (regex_match(IP + ".", IPv4_pattern)) {
      return "IPv4";
    } else if (regex_match(IP + ":", IPv6_pattern)) {
      return "IPv6";
    } else {
      return "Neither";
    }
  }
};