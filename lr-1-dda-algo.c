#include <graphics.h>
#include <stdio.h>
int main() {
  int gd = DETECT, gm, i;
  float x, y, dx, dy, steps;
  int x0, x1, y0, y1;
  printf("Enter x0 = ");
  scanf("%d", &x0);
  printf("Enter x1 = ");
  scanf("%d", &x1);
  printf("Enter y0 = ");
  scanf("%d", &y0);
  printf("Enter y1 = ");
  scanf("%d", &y1);
  initgraph(&gd, &gm, (char *)"");
  dx = (float)(x1 - x0);
  dy = (float)(y1 - y0);
  if (dx >= dy) {
    steps = dx;
  } else {
    steps = dy;
  }
  dy = dy / steps;
  dx = dx / steps;
  x = x0;
  y = y0;
  i = 1;
  while (i <= steps) {
    putpixel(x, y, YELLOW);
    x = x + dx;
    y = y + dy;
    i = i + 1;
  }
  scanf("%d", &i);
  closegraph();
  return 0;
}
