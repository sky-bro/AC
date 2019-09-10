#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char* Strtok(char * str, const char *delimiter){
    static char *start;
    if (str){
        start = str;
    }
    for (;*start && strchr(delimiter, *start); ++start); // 跳过分隔符
    if (!*start){
        return nullptr;
    }
    char *p = start;
    for (;*start && !strchr(delimiter, *start); ++start); // 跳过非分隔符、寻找下次start位置、设置该次结束位置
    if (*start){
        *start = 0;
        ++start;
    }
    return p;
}

int main()
{
    char str[20] = "1,2, 3";
    char *p = Strtok(str, ", ");
    do
    {
        printf("%s\n", p);
    } while (p = Strtok(nullptr, ", "));
    
    return 0;
}