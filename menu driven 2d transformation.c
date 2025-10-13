#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Function to draw original square
void drawSquare(int x[4], int y[4], int color) {
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[3], y[3]);
    line(x[3], y[3], x[0], y[0]);
}

// Translation
void translation(int x[4], int y[4], int tx, int ty) {
    int i;
    for (i = 0; i < 4; i++) {
        x[i] = x[i] + tx;
        y[i] = y[i] + ty;
    }
}

// Scaling
void scaling(int x[4], int y[4], float sx, float sy) {
    int i;
    for (i = 0; i < 4; i++) {
        x[i] = x[i] * sx;
        y[i] = y[i] * sy;
    }
}

int main() {
    int gd = DETECT, gm;
    int choice;
    int x[4] = {200, 300, 300, 200};
    int y[4] = {200, 200, 300, 300};
    int tx, ty;
    float sx, sy;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    setbkcolor(WHITE);
    cleardevice();

    printf("=== 2D TRANSFORMATION MENU ===");
    printf("\n1. Translation");
    printf("\n2. Scaling");
    printf("\n3. Exit");

    while (1) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        cleardevice(); // clear screen before drawing
        setcolor(BLUE);
        drawSquare(x, y, BLUE); // original square
        outtextxy(50, 30, "Blue Square = Original");

        switch (choice) {
            case 1:
                printf("\nEnter translation factors tx and ty: ");
                scanf("%d %d", &tx, &ty);
                translation(x, y, tx, ty);
                setcolor(RED);
                drawSquare(x, y, RED);
                outtextxy(50, 50, "Red Square = After Translation");
                break;

            case 2:
                printf("\nEnter scaling factors sx and sy: ");
                scanf("%f %f", &sx, &sy);
                scaling(x, y, sx, sy);
                setcolor(GREEN);
                drawSquare(x, y, GREEN);
                outtextxy(50, 50, "Green Square = After Scaling");
                break;

            case 3:
                closegraph();
                return 0;

            default:
                printf("\nInvalid choice!");
        }

        delay(500);
    }

    getch();
    closegraph();
    return 0;
}