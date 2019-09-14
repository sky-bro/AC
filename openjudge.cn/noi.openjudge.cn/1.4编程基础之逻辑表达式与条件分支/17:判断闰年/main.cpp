// 公历纪年法中，能被4整除的大多是闰年，但能被100整除而不能被400整除的年份不是闰年， 能被3200整除的也不是闰年，如1900年是平年，2000年是闰年，3200年不是闰年。
// 3200??? 还好输入范围是(0, 3000)

#include <cstdio>

int main(int argc, char const *argv[])
{
  int a;
  scanf("%d", &a);
  if (a%400==0 && a%3200!=0 || a%4==0 && a%100 != 0)
    printf("Y\n");
  else 
    printf("N\n");
  return 0;
}
