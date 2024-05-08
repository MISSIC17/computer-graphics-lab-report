#include <graphics.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  int gd = DETECT, gm, i;
  int x0, y0, r, p;
  int x, y;
  printf("Enter coordinates(x0 and y0) and radius(r) = ");
  scanf("%d%d%d", &x0, &y0, &r);
  initgraph(&gd, &gm, (char *)"");
  x = 0;
  y = r;
  p = (1 - r);
  while (y > x) {
    putpixel(x0 + x, y0 - y, WHITE);
    putpixel(x0 + y, y0 - x, WHITE);
    putpixel(x0 + y, y0 + x, WHITE);
    putpixel(x0 + x, y0 + y, WHITE);
    putpixel(x0 - x, y0 + y, WHITE);
    putpixel(x0 - y, y0 + x, WHITE);
    putpixel(x0 - y, y0 - x, WHITE);
    putpixel(x0 - x, y0 - y, WHITE);
    if (p < 0) {
      p = p + 3 + 2 * x;
    } else {
      p = p + 5 + (2 * x) - (2 * y);
      y = y - 1;
    }
    x = x + 1;
  }
  char c;
  c = getchar();
  closegraph();
  return 0;
}
