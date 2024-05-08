#include <graphics.h>
#include <stdio.h>
int main() {
  int gd = DETECT, gm, i;
  int rx, ry;
  float p1, p2, x0, y0;
  printf("Enter coordinates (x0 and y0) = ");
  scanf("%f%f", &x0, &y0);
  printf("Enter two radius (rx and ry) = ");
  scanf("%d%d", &rx, &ry);
  int x = 0, y = ry;
  p1 = (ry * ry) - (rx * rx * ry) + (rx * rx) / 4;
  initgraph(&gd, &gm, (char *)"");
  while ((2 * ry * ry * x) <= (2 * rx * rx * y)) {
    if (p1 < 0) {
      x = x + 1;
      p1 = p1 + (2.0 * ry * ry * x) + (ry * ry);
    } else {
      x = x + 1;
      y = y - 1;
      p1 = p1 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (ry * ry);
    }
    putpixel(x0 + x, y0 + y, GREEN);
    putpixel(x0 - x, y0 + y, GREEN);
    putpixel(x0 + x, y0 - y, GREEN);
    putpixel(x0 - x, y0 - y, GREEN);
  }
  p2 = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) -
       rx * rx * ry * ry;
  while (y > 0) {
    if (p2 <= 0) {
      x++;
      y--;
      p2 = p2 + (2.0 * ry * ry * x) - (2.0 * rx * rx * y) + (rx * rx);
    } else {
      y--;
      p2 = p2 - (2.0 * rx * rx * y) + (rx * rx);
    }
    putpixel(x0 + x, y0 + y, GREEN);
    putpixel(x0 - x, y0 + y, GREEN);
    putpixel(x0 + x, y0 - y, GREEN);
    putpixel(x0 - x, y0 - y, GREEN);
  }
  getch();
  closegraph();
  return 0;
}
