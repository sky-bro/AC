#include <iostream>
#include <fstream>
#include <cstring>
#include "AC_TAT.h"

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

    vector<Pattern> patterns;

    while (patterns_in.getline(buf, 256)) {
        if (!buf[0]) continue;
        patterns.push_back(Pattern(buf, 0));
    }

    // for (auto it = patterns.begin(); it != patterns.end(); it++) {
    //     cout<<it->str<<it->idx<<endl;
    // }

    pair<int, vector<Pattern> > p0(0, patterns);
    AC my_ac(p0);
    my_ac.print_AC_states();
    my_ac.start_match(in, cout);

    fclose(in);
    patterns_in.close();
    return 0;
}
