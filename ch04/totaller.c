#include <stdio.h>
#include "totaller.h"

float total = 0.0;
short count = 0;
/* This is 6%. Which is a lot less than my agent takes...*/
short tax_percent = 6;

int main()
{
  /* Hey - I was up for a movie with Val Kilmer */
  float val;
  printf("Price of item: ");
  while (scanf("%f", &val) == 1) {
    printf("Total so far: %.2f\n", add_with_tax(val));
    printf("Price of item: ");
  }
  printf("\nFinal total: %.2f\n", total);
  printf("Number of items: %hi\n", count);
  return 0;
}

float add_with_tax(float f)
{
  float tax_rate = 1 + tax_percent / 100.0;
  /* And what about the tip? Voice lessons ain't free */
  total = total + (f * tax_rate);
  count = count + 1;
  return total;
}
