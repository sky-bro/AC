#include <iostream>
#include <cstring>

int kmpNext[100];

/**
 * 填充p_len+1长的数组
 * i处对应元素表示其前面的子串的前缀后缀最大重合长度j, 
 * 但如果j对应字符和i处对应字符相同, 则将本该填充的j改为kmpNext[j]
 * 由子问题不断构造
 */
void initPattern(char *pattern, int p_len){
    int i, j;
    i = 0;
    j = kmpNext[0] = -1; // kmpNext[0]永远都是-1
    while (i < p_len) { // i从0开始到p_len-1, 但每次循环填充的是kmpNext[i+1]
        // 这里的关键是要理解j表示什么含义, 初始什么含义, 为什么要经过这个while循环?
        // 首先本次循环是要填充i+1处的值, 这里的j要表示的就是字串pattern[0...i]的最长前后缀重复长度-1
        while (j > -1 && pattern[i] != pattern[j]) // j最小为-1, 表示重复长度为0
            j = kmpNext [j];
            
        i++, j++;
        // 现在i=i+1, 为要填充的位置, 下面说的i都是增加后的i
        // 现在在i处(现在i处)出现不匹配, 那么我下次应该用模式串的哪个位置再尝试呢?
        if (pattern[i] == pattern[j]) 
        // 如果和i处j处符号相同, 那直接copy人家的值就好了(表示我和之前j处一样,又遇到不匹配): 这里j最小为-1(关键)
        // 同时, 如果这里相等, 下次在更新j时的循环就不会进入, 相当与相对于上一次的j只增加了1
            kmpNext[i] = kmpNext[j];
        else 
            // 如果不同, 那更好了, 可能我当前目标串的符号能和j处的字符匹配: 这里j最小为0(关键)
            kmpNext[i] = j;
    }
}

void kmp(char *target, int t_len, char *pattern, int p_len){
    initPattern(pattern, p_len);
    int i = 0, j = 0;
    while (j < t_len){
        while (i>-1 && pattern[i] != target[j])
            i = kmpNext[i];
        ++i, ++j;
        if (i >= p_len){
            printf("%d\t%s\n", j - i, target + j - i);
            i = kmpNext[i];
        }
        
    }
}

int main(){
    // char target[] ="GCATCGCAGAGAGTATACAGTACG";
    // char pattern[] = "GCAGAGAG";
    char target[] ="ABABABABABABABABABABABAB";
    char pattern[] = "AB";
    kmp(target, strlen(target), pattern, strlen(pattern));
}