#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int translation(int x, int tx) { return (x + tx); }
int scalar(int k, int x) { return (k * x); }
int main() {
  int gd = DETECT, gm, i;
  int left, right, bottom, top;
  printf("Prajjwal Thapaliya\n");
  printf("Enter the coordinates for left = ");
  scanf("%d", &left);
  printf("Enter the coordinates for right = ");
  scanf("%d", &right);
  printf("Enter the coordinates for top = ");
  scanf("%d", &top);
  printf("Enter the coordinates for bottom = ");
  scanf("%d", &bottom);
  initgraph(&gd, &gm, (char *)"");
  rectangle(left, top, right, bottom);
  printf("1. Translation\n2. Reflection\n3. Scaling");
  printf("\nEnter your choise(1/2/3) = ");
  int k;
  scanf("%d", &k);
  switch (k) {
  case 1:
    printf("Enter the x-translating factor = ");
    scanf("%d", &k);
    left = translation(left, k);
    right = translation(right, k);
    printf("Enter the y-translating factor = ");
    scanf("%d", &k);
    top = translation(top, k);
    bottom = translation(bottom, k);
    rectangle(left, top, right, bottom);
    getch();
    break;
  case 2:
    printf("1. About x-axis\n2. About y-axis");
    printf("\nEnter your choice(1/2) = ");
    int n;
    scanf("%d", &n);
    if (n == 1) {
      k = fabs(bottom - top);
      top = bottom;
      rectangle(left, top, right, bottom + k);
    } else if (n == 2) {
      k = fabs(left - right);
      left = right;
      rectangle(left, top, right, bottom + k);
    } else {
      scanf("Wrong choice..");
    }
    getch();
    break;
  case 3:
    printf("Enter the scalar factor = ");
    scanf("%d", &k);
    left = scalar(left, k);
    right = scalar(right, k);
    top = scalar(top, k);
    bottom = scalar(bottom, k);
    rectangle(left, top, right, bottom);
    getch();
    break;
  default:
    printf("Invalid Choice..");
  }
  system("Pause");
  closegraph();
  return 0;
}
