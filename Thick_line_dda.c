#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
	void drawThickPixel(int x, int y ,int thickness , int color){
	int i,j;
	for(i=-thickness/2;i<=thickness;i++){
	for(j=-thickness/2;j<=thickness/2;j++){
	putpixel(x+i,y+j,color);
	}
	}
	}
	void drawThickDDALine  (int x1,int y1,int x2,int y2,int thickness){
	float dx,dy,steps;
	float x, y, x_inc, y_inc;
	int i,color=4;
	dx=x2-x1;
	dy=y2-y1;
	steps=fabs(dx)>fabs(dy)?fabs(dx):fabs(dy);
	x_inc=dx/steps;
	y_inc=dy/steps;
	x=x1;
	y=y1;
	for(i=0;i<=steps;i++){
	drawThickPixel((int)(x+0.5),(int)(y+0.5),thickness,color);
	x+=x_inc;
	y+=y_inc;
	}
	}
	void main(){
	int gd=DETECT,gm;
	int x1=100,y1=150,x2=500,y2=300;
	int thickness=5;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	drawThickDDALine(x1,y1,x2,y2,thickness);
	getch();
	closegraph();
	}


