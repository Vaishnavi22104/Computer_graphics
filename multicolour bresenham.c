#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

// Function to draw a multicolour line using Generalized Bresenham's Algorithm
void multicolorBresenham(int x1, int y1, int x2, int y2) {
    int dx, dy, x, y, p, incx, incy, inc1, inc2, i;
    int color = 1; // Start color (1 to 15 in Turbo C)
    
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
        incx = 1;
    else
        incx = -1;
    if (y2 > y1)
        incy = 1;
    else
        incy = -1;

    x = x1;
    y = y1;

    if (dx > dy) {
        p = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        putpixel(x, y, color);
        for (i = 0; i < dx; i++) {
            x += incx;
            if (p < 0)
                p += inc2;
            else {
                y += incy;
                p += inc1;
            }
            color++;
            if (color > 15)
                color = 1; // Cycle colors 1-15
            putpixel(x, y, color);
        }
    } else {
        p = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        putpixel(x, y, color);
        for (i = 0; i < dy; i++) {
            y += incy;
            if (p < 0)
                p += inc2;
            else {
                x += incx;
                p += inc1;
            }
            color++;
            if (color > 15)
                color = 1; // Cycle colors 1-15
            putpixel(x, y, color);
        }
    }
}

int main() {
    int gd, gm;
    int x1, y1, x2, y2;
    gd = DETECT;
    gm = 0;
    initgraph(&gd, &gm, "C:\\TC\\BGI"); // Graphics path
    setbkcolor(WHITE);
    cleardevice();
    // Example line coordinates
    x1 = 100; y1 = 100;
    x2 = 500; y2 = 300;
    multicolorBresenham(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}