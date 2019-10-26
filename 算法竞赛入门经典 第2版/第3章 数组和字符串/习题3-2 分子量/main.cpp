#include <iostream>
#include <cstring>

char molecule[100];

int main(int argc, const char **argv)
{
    scanf("%s", molecule);
    double base = 0, sum = 0;
    for (int i = 0; molecule[i];)
    {
        switch (molecule[i])
        {
        case 'C':
            base = 12.01;
            break;
        case 'H':
            base = 1.008;
            break;
        case 'O':
            base = 16.00;
            break;
        case 'N':
            base = 14.01;
            break;
        }
        int j = i + 1;
        for (; molecule[j] && !strchr("CHON", molecule[j]); ++j)
            ;
        if (j == i + 1)
        {
            sum += base;
        }
        else
        {
            char tmp = molecule[j];
            molecule[j] = 0;
            sum += base * atoi(molecule + i + 1);
            molecule[j] = tmp;
        }
        i = j;
    }
    printf("%gg/mol\n", sum);
    return 0;
}