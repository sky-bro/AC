#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5;

char mat[N][N];
int I, J;

void print_mat()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (mat[i][j])
            {
                printf("%c ", mat[i][j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, const char **argv)
{
    char c;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> c;
            mat[i][j] = c;
            if (c == '0')
            {
                I = i;
                J = j;
                mat[i][j] = 0;
            }
        }
    }
    while (cin >> c && c != '0')
    {
        switch (c)
        {
        case 'A':
            if (I == 0)
            {
                printf("This puzzle has no final configuration.\n");
                return 0;
            }
            mat[I][J] = mat[I - 1][J];
            I -= 1;
            break;
        case 'B':
            if (I == N)
            {
                printf("This puzzle has no final configuration.\n");
                return 0;
            }
            mat[I][J] = mat[I + 1][J];
            I += 1;
            break;
        case 'L':
            if (J == 0)
            {
                printf("This puzzle has no final configuration.\n");
                return 0;
            }
            mat[I][J] = mat[I][J - 1];
            J -= 1;
            break;
        case 'R':
            if (J == N)
            {
                printf("This puzzle has no final configuration.\n");
                return 0;
            }
            mat[I][J] = mat[I][J + 1];
            J += 1;
            break;
        default:
            print_mat();
            return 0;
        }
        mat[I][J] = 0;
    }
    print_mat();
    return 0;
}