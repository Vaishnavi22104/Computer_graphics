#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ":\\TURBOC3\\BGI");

    setbkcolor(WHITE);
    cleardevice();

    // House base (square)
    setcolor(BLUE);
    rectangle(150, 200, 350, 400);

    // Roof (triangle)
    setcolor(RED);
    line(150, 200, 250, 100);
    line(250, 100, 350, 200);
    line(150, 200, 350, 200);

    // Door (smaller rectangle)
    setcolor(GREEN);
    rectangle(230, 320, 270, 400);

    // Window (square)
    rectangle(180, 240, 220, 280);
    line(180, 260, 220, 260);  // horizontal divider
    line(200, 240, 200, 280);  // vertical divider

    // Text
    setcolor(BLACK);
    outtextxy(180, 420, "Simple House");

    getch();
    closegraph();
    return 0;
}
