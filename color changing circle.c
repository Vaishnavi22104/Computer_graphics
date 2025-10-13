#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

// Function to draw a thick rainbow circle
void thickRainbowCircle(int centerX, int centerY, int radius, int thickness) {
    double theta;
    int color;
    double step = 0.01; // step size determines smoothness of circle

    for (int t = 0; t < thickness; t++) { // Draw multiple concentric circles
        color = 1; // start color for each concentric layer
        int r = radius + t; // increase radius slightly for each layer

        for (theta = 0; theta <= 2 * PI; theta += step) {
            int x = centerX + r * cos(theta);
            int y = centerY + r * sin(theta);

            putpixel(x, y, color);

            color++; // change color gradually
            if (color > 15) // Turbo C++ supports colors 1–15
                color = 1;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int centerX, centerY, radius, thickness;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    setbkcolor(WHITE);
    cleardevice();

    // Circle parameters
    centerX = 300;
    centerY = 250;
    radius = 100;
    thickness = 10;

    thickRainbowCircle(centerX, centerY, radius, thickness);

    getch();
    closegraph();
    return 0;
}