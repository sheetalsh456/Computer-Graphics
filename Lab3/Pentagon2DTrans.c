#include <stdio.h>
#include <graphics.h>
#include <math.h>

int graDriver=DETECT,graMode;
int n,xs[100],ys[100],i,xp,yp,degree;
float radian;

void rotation();
void DrawFn();

void degToRad()
{
radian=(float)degree*3.14f/180;
}

void main()
{
	n=5;
	xs[0]=100;
	ys[0]=100;
	xs[1]=50;
	ys[1]=150;
	xs[2]=150;
	ys[2]=200;
	xs[3]=250;
	ys[3]=150;
	xs[4]=200;
	ys[4]=100;
	xp =100;
	yp=100;
	degree=60;
	degToRad();
	initgraph(&graDriver,&graMode," ");
	cleardevice();
	//Drawing original in RED color
	setcolor(RED);
	DrawFn();
	//cleardevice();
	for(i=0;i<5;i++)
	{
		xs[i]+=25;
		ys[i]+=50;
	}
	DrawFn();
	
	for(i=0;i<5;i++)
	{
		xs[i]-=125;
		ys[i]-=150;
	}

	for(i=0;i<5;i++)
	{
		xs[i]*=2;
		ys[i]*=2;
	}
	for(i=0;i<5;i++)
	{
		xs[i]+=125;
		ys[i]+=150;
	}
	DrawFn();
	setcolor(BLUE);
	DrawFn();
	getch();
}

void DrawFn()
{
	for(i=0;i<n;i++)
	 line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
}

