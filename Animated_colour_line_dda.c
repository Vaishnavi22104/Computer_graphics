#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

void main(){
	int gd=DETECT, gm;
	float x1, y1, x2, y2, dx, dy, steps, x, y;
	int i, r, g, b, color;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	x1=100;
	y1=100;
	x2=500;
	y2=300;
	dx=x2-x1;
	dy=y2-y1;

	steps=fabs(dx)>fabs(dy)? fabs(dx):fabs(dy);
	dx=dy/steps;
	dy=dy/steps;
	x=x1;
	y=y1;

	for(i=0; i<=steps; i++){
	color = i%15+1;
	putpixel((int)(x+0.5), (int)(y+0.5), color);
	delay(5);
	x+=dx;
	y+=dy;
	}
getch();
closegraph();
}
