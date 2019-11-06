#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include "AC.h"

using namespace std;

char buf[256];

int main(int argc, char const *argv[])
{
    FILE *in = fopen("input.txt", "r");
    if (!in) {
        perror("open input.txt failed");
        return -1;
    }
    // FILE *pattern_file = fopen("patterns.txt", "r");
    ifstream patterns_in;
    patterns_in.open("patterns.txt");

    map<string, int> patterns;
    while (patterns_in.getline(buf, 256)) {
        patterns[buf] = strlen(buf);
    }

    for (auto it = patterns.begin(); it != patterns.end(); it++) {
        cout<<it->first<<it->second<<endl;
    }

    AC my_ac(patterns);
    my_ac.start_match(in, stdout);

    fclose(in);
    patterns_in.close();
    return 0;
}
