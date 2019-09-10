#include <cstdio>

int _day_of_week(int year, int month, int day=1) {
  if (month == 1 || month == 2) {
    --year;
    month += 12;
  }
  // 0 -- Sunday 1 -- Monday
  return (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400 + 1) % 7;
}

void print_month(int day_of_week, int days) {
  printf("Sun Mon Tue Wed Thu Fri Sat\n");
  for (int i = 0; i < day_of_week; ++i) {
    printf("    "); // for spaces
  }
  int d;
  for (int i = 0; i < days; ++i) {
    d = (day_of_week + i) % 7;
    if (d == 6) {
      printf("%3d\n", i+1);
    } else {
      printf("%3d ", i+1);
    }
  }
  printf("\n");
}

int _days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char const *argv[])
{
  int year, month;
  scanf("%d%d", &year, &month);
  int days = _days[month];
  // 闰年2月天数+1
  if ( month==2 && 
     ( (!(year%4) && year%100) || !(year % 400)) ){
    days += 1;
  }
  int day_of_week = _day_of_week(year, month);
  print_month(day_of_week, days);
  return 0;
}
