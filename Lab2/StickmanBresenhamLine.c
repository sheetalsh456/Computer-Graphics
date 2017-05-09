#include <graphics.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void drawline(int x1, int y1, int x2, int y2)
{
	int dx,dy,x,y,e,sign;

	if(x1 > x2)
	{
		swap(&x1,&x2);
		swap(&y1,&y2);
	}

	dx = x2 - x1;
	dy = y2 - y1;
	sign = dy >= 0 ? 1 : -1;

	e = 0;
	x = x1;
	y = y1;

	if(sign * dy <= dx)
	{
		while(x <= x2)
		{
			putpixel(x,y,GREEN);
			x ++;
			if( sign * 2 * (e + dy) < dx )
			{
				e = e + dy;
			}
			else
			{
				y += sign;
				e = e + dy - sign*dx;
			}
		}
	}
	else
	{
		while((sign*y) <= (sign*y2))
		{
			putpixel(x,y,GREEN);
			y += sign;
			if( sign * 2 * (e + sign * dx) < dy )
			{
				e = e + sign * dx;
			}
			else
			{
				x ++;
				e = e + sign * dx - dy;
			}
		}
	}
	return;
}
void drawcircle(int xc,int yc, int r, int color)
{
	int x=0;
    int y=r;
    int Pk=1-r;
    putpixel(xc+x,yc+y,color);
    putpixel(xc+y,yc+x,color);
    putpixel(xc-y,yc+x,color);
    putpixel(xc-x,yc+y,color);
    putpixel(xc-x,yc-y,color);
    putpixel(xc-y,yc-x,color);
    putpixel(xc+y,yc-x,color);
    putpixel(xc+x,yc-y,color);
    while(x<y)
    {
        if(Pk<0)
        {
            x=x+1;
            Pk=Pk+(2*x)+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            Pk=Pk+(2*x)-(2*y)+1;
        }
        putpixel(xc+x,yc+y,color);
    	putpixel(xc+y,yc+x,color);
    	putpixel(xc-y,yc+x,color);
    	putpixel(xc-x,yc+y,color);
    	putpixel(xc-x,yc-y,color);
    	putpixel(xc-y,yc-x,color);
    	putpixel(xc+y,yc-x,color);
    	putpixel(xc+x,yc-y,color);
    }
}
int main() {
    int gd = DETECT, gm;
    /* initialization of graphic mode */
    initgraph(&gd, &gm, " "); 
    drawline(100,150,100,350);
    drawline(100,250,150,200);
    drawline(100,250,50,200);
    drawline(100,350,50,400);
    drawline(100,350,150,400);

    //drawline(100,100,150,5);
    drawcircle(100,100,50,GREEN);
    getch();
    closegraph();
    return 0;
}
