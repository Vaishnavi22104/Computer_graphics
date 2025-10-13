#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h> // for delay

#define PI 3.14159265

void movingPointCircle(int centerX, int centerY, int radius) {
    double theta;
    int x, y, oldx, oldy;
    int i;
    // Draw thick circle border (light gray)
    setcolor(LIGHTGRAY);
    for(i = 0; i < 4; i++) 
        circle(centerX, centerY, radius - i);

    // Initialize previous coordinates outside screen
    oldx = oldy = -1;

    // Animate single large point clockwise
    for(theta = 0; theta < 2 * PI; theta += 0.02) {
        // Erase previous point (only, not the circle)
        if(oldx != -1 && oldy != -1) {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL, WHITE);
            fillellipse(oldx, oldy, 6, 6);
        }

        // Compute new position
        x = centerX + radius * cos(theta);
        y = centerY + radius * sin(theta);

        // Draw new red moving point
        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        fillellipse(x, y, 6, 6); // bigger, visible point

        // Redraw circle to cover any erased overlap
        setcolor(LIGHTGRAY);
        for(i = 0; i < 4; i++)
            circle(centerX, centerY, radius - i);

        // Save previous coordinates
        oldx = x;
        oldy = y;

        delay(30); // adjust for smooth speed
    }
}

int main() {
    int gd = DETECT, gm;
    int centerX = 320, centerY = 240, radius = 100;
    initgraph(&gd, &gm, "C:");
    setbkcolor(WHITE);
    cleardevice();

    movingPointCircle(centerX, centerY, radius);

    getch();
    closegraph();
    return 0;
}