#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>  // for delay()

void ddaLine(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float X = x1;
    float Y = y1;
    int i;

    for (i = 0; i <= steps; i++) {
	putpixel((int)(X + 0.5), (int)(Y + 0.5), WHITE);
	delay(10);  // delay to animate the drawing
	X += Xinc;
	Y += Yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");  // Adjust BGI path if needed

    printf("Enter x1, y1: ");
    scanf("%d%d", &x1, &y1);

    printf("Enter x2, y2: ");
    scanf("%d%d", &x2, &y2);

    ddaLine(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
