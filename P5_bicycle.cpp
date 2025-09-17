#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Wheels
    int leftWheelX = 150, leftWheelY = 350, wheelRadius = 50;
    int rightWheelX = 400, rightWheelY = 350;

    circle(leftWheelX, leftWheelY, wheelRadius);    // Left wheel
    circle(rightWheelX, rightWheelY, wheelRadius);  // Right wheel

    // Wheel hubs
    circle(leftWheelX, leftWheelY, 8);
    circle(rightWheelX, rightWheelY, 8);

    // Frame - Draw the diamond frame (two triangles joined)

    // Bottom frame line (chainstay)
    line(leftWheelX, leftWheelY, rightWheelX, rightWheelY);

    // Seat tube (left wheel to seat)
    int seatX = 240, seatY = 270;
    line(leftWheelX, leftWheelY, seatX, seatY);

    // Top tube (seat to handlebar)
    int handlebarX = 330, handlebarY = 270;
    line(seatX, seatY, handlebarX, handlebarY);

    // Down tube (handlebar to right wheel)
    line(handlebarX, handlebarY, rightWheelX, rightWheelY);

    // Seat post (vertical line)
    line(seatX, seatY, seatX, seatY - 30);

    // Seat (horizontal line on top of seat post)
    line(seatX - 20, seatY - 30, seatX + 20, seatY - 30);

    // Handlebar stem (vertical line)
    line(handlebarX, handlebarY, handlebarX, handlebarY - 43);

    // Handlebar (horizontal line on top of stem)
    line(handlebarX - 40, handlebarY - 60, handlebarX + 40, handlebarY - 30);

    // Pedal crank center (circle)
    int pedalCenterX = 275, pedalCenterY = 350;
    circle(pedalCenterX, pedalCenterY, 15);

    // Pedal arms
    line(pedalCenterX, pedalCenterY, pedalCenterX - 15, pedalCenterY + 15);
    line(pedalCenterX, pedalCenterY, pedalCenterX + 15, pedalCenterY - 15);

    getch();
    closegraph();
    return 0;
}
