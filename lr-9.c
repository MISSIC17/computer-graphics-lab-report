#include <graphics.h>
#include <math.h>
#include <stdio.h>
int main() {
  int gd = DETECT, gm, i;
  int x1, y1, x2, y2, xmax, ymax, xmin, ymin, xx1, xx2, yy1, yy2, dx, dy;
  float t1, t2, p[4], q[4], temp;
  printf("Enter xmin, ymin = ");
  scanf("%d%d", &xmin, &ymin);
  printf("Enter xmax, ymax = ");
  scanf("%d%d", &xmax, &ymax);
  printf("Enter the starting point x and y = \n");
  scanf("%d%d", &x1, &y1);
  printf("Enter the ending point x and y = \n");
  scanf("%d%d", &x2, &y2);
  initgraph(&gd, &gm, (char *)"");
  cleardevice();
  rectangle(xmin, ymin, xmax, ymax);
  line(x1, y1, x2, y2);
  dx = (x2 - x1);
  dy = (y2 - y1);
  p[0] = -dx;
  p[1] = dx;
  p[2] = -dy;
  p[3] = dy;
  q[0] = x1 - xmin;
  q[1] = xmax - x1;
  q[2] = y1 - ymin;
  q[3] = ymax - y1;
  for (i = 0; i < 4; i++) {
    if (p[i] == 0) {
      printf("Line is parallel");
    }
    if (q[i] == 0) {
      if (i < 2) {
        if (y1 < ymin) {
          y1 = ymin;
        }
        if (y2 > ymax) {
          y2 = ymax;
        }
        line(x1, y1, x2, y2);
      }
      if (i > 1) {
        if (x1 < xmin) {
          x1 = xmin;
        }
        if (x2 > xmax) {
          x2 = xmax;
        }
        line(x1, y1, x2, y2);
      }
    }
  }
  t1 = 0;
  t2 = 1;
  for (i = 0; i < 4; i++) {
    temp = q[i] / p[i];
    if (p[i] < 0) {
      t1 = temp;
    } else {
      if (t2 > temp) {
        t2 = temp;
      }
    }
  }
  if (t1 < t2) {
    xx1 = x1 + t1 * p[i];
    xx2 = x1 + t2 * p[1];
    yy1 = y1 + t1 * p[3];
    yy2 = y1 + t2 * p[3];
    delay(7000);
    clearviewport();
    rectangle(xmin, ymin, xmax, ymax);
    line(xx1, yy1, xx2, yy2);
  }
  delay(7000);
  getch();
  closegraph();
  return 0;
}
