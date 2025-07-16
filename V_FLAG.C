#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void drawAshokaChakra(int x, int y, int r) {
    int i;
    setcolor(BLUE);
    circle(x, y, r);

    // Draw 24 spokes
    for (i = 0; i < 24; i++) {
	float angle = i * (360.0 / 24) * (3.14 / 180);
	int x1 = x + r * cos(angle);
	int y1 = y + r * sin(angle);
	line(x, y, x1, y1);
    }
}

int main() {
    int gd = DETECT, gm;
    int left = 100, top = 100;
    int width =300, height = 100;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setbkcolor(WHITE);
    cleardevice();

    // Saffron stripe
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTRED);
    rectangle(left, top, left + width, top + height);
    floodfill(left + 1, top + 1, WHITE);

    // White stripe
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(left, top + height, left + width, top + 2 * height);
    floodfill(left + 1, top + height + 1, WHITE);

    // Green stripe
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(left, top + 2 * height, left + width, top + 3 * height);
    floodfill(left + 1, top + 2 * height + 1, WHITE);

    // Ashoka Chakra
    drawAshokaChakra(left + width / 2, top + height + height / 2, 20);

    // Flagpole
    setcolor(BROWN);
    line(left, top, left, top + 300);

    // Text
    setcolor(BLUE);
    outtextxy(150, top + 3 * height + 20, "INDIAN NATIONAL FLAG");

    getch();
    closegraph();
    return 0;
}
