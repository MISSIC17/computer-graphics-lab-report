
#include <graphics.h>
#include <stdio.h>
int main() {
  int gd = DETECT, gm, i;
  float x, y, dx, dy, steps, pl;
  int x1, x2, y1, y2;
  printf("Enter x0 and x1 = ");
  scanf("%d%d", &x1, &x2);
  printf("Enter y0 and y1 = ");
  scanf("%d%d", &y1, &y2);
  initgraph(&gd, &gm, (char *)"");
  dx = (float)(x2 - x1);
  dy = (float)(y2 - y1);
  pl = 2 * dy - dx;
  x = x1;
  y = y1;
  while (x <= x2) {
    putpixel(x, y, WHITE);
    x++;
    if (pl < 0) {
      pl = pl + 2 * dy;
    } else {
      pl = pl + (2 * dy) - (2 * dx);
      y++;
    }
  }
  getchar();
  closegraph();
  return 0;
}
