#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    int cnt[128]{0};
    for (char c : s) {
      ++cnt[c];
    }
    int res = 0;
    int m = 0;
    for (int i = 'A'; i <= 'z'; ++i) {
      res += cnt[i];
      if (cnt[i] & 1) {
        // odd
        m = max(cnt[i], m);
        --res;
      }
    }
    return res + (m != 0);
  }
};

int main(int argc, char const *argv[]) {
  Solution sol;
  string s;
  s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedca"
      "nlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpatea"
      "portionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatt"
      "hatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalar"
      "gersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebra"
      "velmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwe"
      "rtoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayhereb"
      "utitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedhe"
      "retotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedIt"
      "isratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromt"
      "hesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelast"
      "pfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavedi"
      "edinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernm"
      "entofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
  cout << sol.longestPalindrome(s) << endl;
  while (cin >> s) {
    cout << sol.longestPalindrome(s) << endl;
  }
  return 0;
}
