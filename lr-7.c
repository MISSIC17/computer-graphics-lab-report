#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int translation(int x, int tx) { return (x + tx); }
int scalar(int x, int k) { return (k * x); }
int main() {
  int gd = DETECT, gm, i, centerX, centerY;
  printf("Enter the coordinates of cube (x1,y1,x2,y2) = ");
  int left, right, bottom, top, depth;
  scanf("%d%d%d%d", &left, &top, &right, &bottom);
  initgraph(&gd, &gm, (char *)"");
  depth = fabs((right - left) / 2);
  bar3d(left, top, right, bottom, depth, 1);
  // getch();
  printf("1. Translation\n2. Scaling\n");
  printf("Enter your choise(1/2) = ");
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
    bar3d(left, top, right, bottom, depth, 1);
    getch();
    break;
  case 2:
    printf("Assuming even scaling on all axis, Enter the scalar factor = ");
    scanf("%d", &k);
    centerX = (left + right) / 2;
    centerY = (top + bottom) / 2;
    left = centerX + scalar(left - centerX, k);
    right = centerX + scalar(right - centerX, k);
    top = centerY + scalar(top - centerY, k);
    bottom = centerY + scalar(bottom - centerY, k);
    depth = fabs((right - left) / 2);
    bar3d(left, top, right, bottom, depth, 1);
    getch();
    break;
  default:
    printf("Invalid Choice..");
  }
  system("Pause");
  closegraph();
  return 0;
}
