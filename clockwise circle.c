#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

// Function to draw a clockwise arrow along a circle
void drawClockwiseArrow(int centerX, int centerY, int radius) {
    int x1, y1, x2, y2;
    double theta;
    double arrowLength = 10;

    // Draw circle path (optional)
    setcolor(RED);
    circle(centerX, centerY, radius);

    // Arrow position on circle (e.g., at 0 degree)
    theta = 0; // start angle in radians
    x1 = centerX + radius * cos(theta);
    y1 = centerY + radius * sin(theta);

    // Arrow shaft (a short line along clockwise tangent)

    x2 = x1;
    y2 = y1 + arrowLength; // downward tangent for clockwise

    setcolor(RED);
    line(x1, y1, x2, y2);

    // Arrowhead
    line(x2, y2, x2 - 10, y2 - 10); // left head
    line(x2, y2, x2 + 10, y2 - 10); // right head
}

int main() {
    int gd, gm;
    int centerX, centerY, radius;

    gd = DETECT;
    gm = 0;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setbkcolor(WHITE
    );
    cleardevice();

    centerX = 300;
    centerY = 250;
    radius = 100;

    drawClockwiseArrow(centerX, centerY, radius);

    getch();
    closegraph();
    return 0;
}