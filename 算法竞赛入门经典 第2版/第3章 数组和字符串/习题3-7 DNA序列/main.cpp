#include <iostream>

using namespace std;

const int M = 60, N = 1010;

char dna[N];
int mat[N][4];

char CHAR[] = "ACGT";

int main(int argc, const char **argv)
{
    int cntA, cntC, cntG, cntT, m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        scanf("%s", dna);
        for (int j = 0; j < n; ++j)
        {
            switch (dna[j])
            {
            case 'A':
                mat[j][0]++;
                break;
            case 'C':
                mat[j][1]++;
                break;
            case 'G':
                mat[j][2]++;
                break;
            case 'T':
                mat[j][3]++;
                break;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int k = 0, max = 0;
        sum += mat[i][k];
        for (int j = 1; j < 4; ++j)
        {
            sum += mat[i][j];
            if (mat[i][j] > mat[i][k])
            {
                k = j;
                max = mat[i][j];
            }
        }
        dna[i] = CHAR[k];
        sum -= max;
    }
    printf("%d\n", sum);
    printf("%s\n", dna);
    return 0;
}