#include <iostream>
#include <cstring>

int bf(char *target, int t_len, char *pattern, int p_len){
    for (int i = 0; i <= t_len - p_len; ++i){
        int j = 0;
        for (; j < p_len && pattern[j] == target[i+j]; ++j);
        if (j == p_len)
            return i;
    }
    return -1;
}

int main(){
    char target[] ="GCATCGCAGAGAGTATACAGTACG";
    char pattern[] = "GCAGAGAG";
    int i = bf(target, strlen(target), pattern, strlen(pattern));
    if (i > 0)
        printf("%d\n%s\n", i, target + i);
    else 
        printf("pattern not found!\n");
    return 0;
}