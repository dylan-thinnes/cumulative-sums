#include <stdio.h>

void main () {
  int x = 0;
  int y = 0;
  while (1 == scanf("%d\n", &y)) x += y;
  printf("%d\n", x);
}
