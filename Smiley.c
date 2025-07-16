#include <graphics.h>
#include <conio.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Set background color to WHITE
    setbkcolor(WHITE);
    cleardevice();

    // Face outline
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(250, 200, 100);
    floodfill(250, 200, YELLOW);

    // Eyes
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    circle(215, 170, 8); // Left eye
    floodfill(215, 170, BLACK);

    circle(285, 170, 8); // Right eye
    floodfill(285, 170, BLACK);

    // Eyebrows
    setcolor(BLACK);
    line(205, 155, 225, 160); // Left eyebrow
    line(275, 160, 295, 155); // Right eyebrow

    // Smile (semi-circle mouth using arc)
    setcolor(RED);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    arc(250, 220, 200, 340, 40); // smiling arc

    // Optional: Text
    setcolor(BLUE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(180, 320, "KEEP SMILING!");

    getch();
    closegraph();
    return 0;
}
