#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Base parameters
    int baseY = 350;

    // Draw towers (rectangles)
    // Left tower
    rectangle(100, 200, 160, baseY);
    // Middle tower
    rectangle(240, 180, 300, baseY);
    // Right tower
    rectangle(380, 200, 440, baseY);

    // Draw roofs (triangles) on towers
    // Left tower roof
    line(100, 200, 130, 150);
    line(130, 150, 160, 200);
    line(100, 200, 160, 200);

    // Middle tower roof (a taller triangle)
    line(240, 180, 270, 120);
    line(270, 120, 300, 180);
    line(240, 180, 300, 180);

    // Right tower roof
    line(380, 200, 410, 150);
    line(410, 150, 440, 200);
    line(380, 200, 440, 200);

    // Draw castle walls (rectangle)
    rectangle(160, 280, 380, baseY);

    // Draw battlements (small rectangles on top of walls)
    for (int x = 160; x <= 360; x += 40) {
        rectangle(x, 260, x + 20, 280);
    }

    // Draw gates (arc at base center)
    arc(270, baseY, 0, 180, 50);
    line(220, baseY, 320, baseY);

    // Draw flags on towers (lines + triangles)
    // Left tower flagpole
    line(130, 150, 130, 110);
    // Left flag (triangle)
    line(130, 110, 140, 120);
    line(140, 120, 130, 130);
    line(130, 130, 130, 110);

    // Middle tower flagpole
    line(270, 120, 270, 70);
    // Middle flag (triangle)
    line(270, 70, 280, 80);
    line(280, 80, 270, 90);
    line(270, 90, 270, 70);

    // Right tower flagpole
    line(410, 150, 410, 110);
    // Right flag (triangle)
    line(410, 110, 420, 120);
    line(420, 120, 410, 130);
    line(410, 130, 410, 110);

    getch();
    closegraph();
    return 0;
}
