#include <cstdio>

int main(int argc, char const *argv[])
{
  int budget, in_hand=0, in_mom=0, tmp;
  int month = 1;
  for (; month <= 12; ++month) {
    scanf("%d", &budget);
    if (in_hand+300 < budget) {
      break;
    }
    tmp = in_hand+300-budget;
    in_hand = tmp%100;
    in_mom += (tmp-in_hand)/100;
  }

  

  if (month == 13) {
    printf("%d\n", in_hand+in_mom*120);
  } else {
    for (int i = month;i<12;++i)scanf("%d", &budget);
    printf("-%d\n", month);
  }
  return 0;
}
