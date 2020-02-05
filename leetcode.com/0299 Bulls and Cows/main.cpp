#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        char secret_cs[10]{};
        char guess_cs[10]{};
        for (int i = 0; i < secret.length(); ++i) {
            secret_cs[secret[i]-'0']++;
            guess_cs[guess[i]-'0']++;
            if (secret[i] == guess[i]) ++bulls;
        }

        cows -= bulls;
        for (int i = 0; i < 10; ++i) {
            cows += min(secret_cs[i], guess_cs[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};