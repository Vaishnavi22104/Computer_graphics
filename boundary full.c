#include <graphics.h>
#include <conio.h>
#include <math.h>

// Boundary Fill function (4-connected)
void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);

    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);

        // Recursive calls in 4 directions
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

// Function to draw a hexagon-shaped star
void drawStarOfHexagon(int centerX, int centerY, int radius) {
    int points[14]; // 6 vertices + 1st vertex repeated
    int i, angle = 0;

    // Outer hexagon points
    for (i = 0; i < 6; i++) {
        points[i * 2] = centerX + radius * cos((angle * 3.14159) / 180);
        points[i * 2 + 1] = centerY + radius * sin((angle * 3.14159) / 180);
        angle += 60;
    }

    // Repeat first vertex to close shape
    points[12] = points[0];
    points[13] = points[1];

    // Draw outer hexagon
    setcolor(BLUE);
    drawpoly(7, points);

    // Draw star by connecting alternate vertices
    setcolor(RED);
    line(points[0], points[1], points[4], points[5]);
    line(points[4], points[5], points[8], points[9]);
    line(points[8], points[9], points[2], points[3]);
    line(points[2], points[3], points[6], points[7]);
    line(points[6], points[7], points[10], points[11]);
    line(points[10], points[11], points[0], points[1]);
}

int main() {
    int gd = DETECT, gm;
    int centerX = 320, centerY = 240, radius = 100;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw hexagon star
    drawStarOfHexagon(centerX, centerY, radius);

    // Fill the star area
    boundaryFill4(centerX, centerY, YELLOW, RED);

    getch();
    closegraph();
    return 0;
}