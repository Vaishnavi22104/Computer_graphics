#include <graphics.h>
#include <conio.h>
#include <dos.h>

// Function to draw a tall tree at position (x, y)
void drawTallTree(int x, int y) {
    int i;

    // Draw long trunk
    setcolor(BROWN);
    setfillstyle(SOLID_FILL, BROWN);
    rectangle(x, y, x + 30, y + 200);  // Tall trunk
    floodfill(x + 1, y + 1, BROWN);

    // Draw large leafy top using multiple overlapping circles
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);

    // Main central leaf
    circle(x + 15, y - 50, 60);
    floodfill(x + 15, y - 50, GREEN);

    // Left side leaves
    circle(x - 40, y, 50);
    floodfill(x - 40, y, GREEN);

    circle(x - 20, y - 40, 45);
    floodfill(x - 20, y - 40, GREEN);

    // Right side leaves
    circle(x + 70, y, 50);
    floodfill(x + 70, y, GREEN);

    circle(x + 40, y - 40, 45);
    floodfill(x + 40, y - 40, GREEN);

    // Top leaf for extra height
    circle(x + 15, y - 100, 40);
    floodfill(x + 15, y - 100, GREEN);
}

int main() {
    int gd, gm;
    int x, y;

    gd = DETECT;
    gm = 0;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    setbkcolor(WHITE);
    cleardevice();

    x = 350;  // X position of tree
    y = 350;  // Y position of trunk base

    drawTallTree(x, y);

    getch();
    closegraph();
    return 0;
}