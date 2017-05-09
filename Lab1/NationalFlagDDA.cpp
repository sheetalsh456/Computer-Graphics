# include <graphics.h>
# include <math.h>
void DDALine(float x1, float y1, float x2, float y2,int color);
void drawcircle(int r, double theta);
int main()
{
	int gDriver=DETECT,gMode;
	int x1,x2,y1,y2,iColor,i;
	initgraph(&gDriver,&gMode," ");
    cleardevice();
    // Outline
    DDALine(100,100,500,100,12);
	DDALine(500,100,500,400,12);
	DDALine(500,400,100,400,12);
	DDALine(100,400,100,100,12);
	DDALine(100,200,500,200,12);
	DDALine(100,300,500,300,12);

	// Coloring the 3 parts
	for(i=101;i<=199;i++)
	{
		DDALine(100,i,500,i,12);
	}	
	for(i=301;i<=399;i++)
	{
		DDALine(100,i,500,i,3);
	}
	for(i=201;i<=299;i++)
	{
		DDALine(100,i,500,i,15);
	}

	// Drawing the circle
	for(i=0;i<=360;i++)
	{
    	drawcircle(50,i);
	}

	// Drawing the 4 horizontal and vertical spokes
	DDALine(300,250,350,250,1);
	DDALine(300,250,250,250,1);
	DDALine(300,250,300,200,1);
	DDALine(300,250,300,300,1);

	// Drawing the other 20 spokes
	for(i=1;i<=5;i++)
	{
		DDALine(300,250,300+50*cos(i*15 * 3.14 / 180.0),250+50*sin(i*15 * 3.14 / 180.0),1);
		DDALine(300,250,300+50*cos(i*15 * 3.14 / 180.0),250-50*sin(i*15 * 3.14 / 180.0),1);
		DDALine(300,250,300-50*cos(i*15 * 3.14 / 180.0),250+50*sin(i*15 * 3.14 / 180.0),1);
		DDALine(300,250,300-50*cos(i*15 * 3.14 / 180.0),250-50*sin(i*15 * 3.14 / 180.0),1);
	}
	getch();
	return 0;
}

void DDALine(float x1, float y1, float x2, float y2,int color)
{
	int i;
	float x,y,dx,dy,pixel,temp;
	dx=(x2-x1);
    dy=(y2-y1);

    if(fabs(dx)>=fabs(dy))
    pixel=fabs(dx);
    else
    pixel=fabs(dy);

    dx=dx/pixel;
    dy=dy/pixel;

    x=x1;
    y=y1;

    i=1;
    while(i<=pixel)
    {
          putpixel(x,y,color);
          x=x+dx;
          y=y+dy;
          i++;
    }
}
void drawcircle(int r, double theta)
{
	float dx,dy,x,y;
	dx = round(r*cos(theta));
	dy = round(r*sin(theta));
	x = 300;
	y = 250;
	putpixel(x+dx,y+dy,1);
}
