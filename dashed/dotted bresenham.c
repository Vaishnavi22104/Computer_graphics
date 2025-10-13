#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

// Function to draw a dashed/dotted line using Generalized Bresenham's Algorithm
void dashedLine(int x1, int y1, int x2, int y2, int dashLength) {
    int dx, dy, x, y, p, incx, incy, inc1, inc2, i;
    int count = 0;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1) incx = 1; else incx = -1;
    if (y2 > y1) incy = 1; else incy = -1;

    x = x1;
    y = y1;

    if (dx > dy) {
        p = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;

        for (i = 0; i <= dx; i++) {
            // Draw pixel only if within dash length
            if (count < dashLength) {
                putpixel(x, y, RED);
            }
            count = (count + 1) % (2 * dashLength); // skip for dash effect

            x += incx;
            if (p < 0)
                p += inc2;
            else {
                y += incy;
                p += inc1;
            }
        }
    } else {
        p = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;

        for (i = 0; i <= dy; i++) {
            if (count < dashLength) {
                putpixel(x, y, RED);
            }
            count = (count + 1) % (2 * dashLength);
            y += incy;
            if (p < 0)
                p += inc2;
            else {
                x += incx;
                p += inc1;
            }
        }
    }
}

int main() {
    int gd, gm;
    int x1, y1, x2, y2;
    int dashLength;
    gd = DETECT;
    gm = 0;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    cleardevice();

    // Example line coordinates
    x1 = 100; y1 = 100;
    x2 = 500; y2 = 300;
    dashLength = 5; // Length of dash segments

    dashedLine(x1, y1, x2, y2, dashLength);

    getch();
    closegraph();
    return 0;
}