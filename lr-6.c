#include <graphics.h>
#include <math.h>
#include <stdio.h>
int main() {
  int gd = DETECT, gm, i;
  int x[4], y[4];
  double put_x, put_y, t;
  printf("\nBezier Curve\n");
  for (i = 0; i < 4; i++) {
    printf("Enter x[%d] and y[%d] coordinates = ", i + 1, i + 1);
    scanf("%d%d", &x[i], &y[i]);
  }
  initgraph(&gd, &gm, (char *)"");
  for (t = 0.0; t < 1.0; t = t + 0.0005) {
    put_x = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] +
            3 * t * t * (1 - t) * x[2] + pow(t, 3) * x[3];
    put_y = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] +
            3 * t * t * (1 - t) * y[2] + pow(t, 3) * y[3];
    putpixel(put_x, put_y, WHITE);
  }
  getchar();
  closegraph();
  return 0;
}
