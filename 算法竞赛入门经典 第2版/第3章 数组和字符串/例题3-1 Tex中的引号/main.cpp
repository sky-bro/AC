#include <cstdio>

int main(int argc, const char **argv)
{
    int c, q = 1;
    while ((c = fgetc(stdin)) != EOF)
    {
        if (c == '"')
        {
            printf("%s", q ? "``" : "''");
            q = !q;
        }
        else
        {
            printf("%c", c);
        }
    }
    return 0;
}