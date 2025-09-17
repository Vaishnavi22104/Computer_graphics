#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Background Black

    cleardevice();

    // Rocket body (rectangle)
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(280, 150, 360, 350);
    floodfill(285, 160, WHITE);

    // Rocket nose (triangle)
    setfillstyle(SOLID_FILL, RED);
    line(280, 150, 320, 100);   // left side
    line(360, 150, 320, 100);   // right side
    line(280, 150, 360, 150);   // base
    floodfill(320, 120, WHITE);

    // 3 Windows (circles)
    setfillstyle(SOLID_FILL, BLUE);
    circle(320, 180, 15);
    floodfill(320, 180, WHITE);

    circle(320, 230, 15);
    floodfill(320, 230, WHITE);

    circle(320, 280, 15);
    floodfill(320, 280, WHITE);

    // Rocket fins
    setfillstyle(SOLID_FILL, BLACK);
    line(280, 350, 250, 390);   // left fin
    line(280, 350, 280, 390);
    line(250, 390, 280, 390);
    floodfill(260, 370, WHITE);

    setfillstyle(SOLID_FILL, BLACK);
    line(360, 350, 390, 390);   // right fin
    line(360, 350, 360, 390);
    line(390, 390, 360, 390);
    floodfill(370, 370, WHITE);

    // Flames (multi-layer for realism)
    setfillstyle(SOLID_FILL, RED);
    ellipse(320, 400, 0, 360, 25, 50);
    floodfill(320, 420, WHITE);

    ellipse(320, 420, 0, 360, 18, 35);
    floodfill(320, 430, WHITE);

    setfillstyle(SOLID_FILL, YELLOW);
    ellipse(320, 440, 0, 360, 10, 20);
    floodfill(320, 445, WHITE);

    // Text
    setcolor(LIGHTCYAN);
    outtextxy(250, 50, "Rocket Launch!");

    getch();
    closegraph();
    return 0;
}
