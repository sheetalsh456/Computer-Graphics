#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int outcode;

outcode CompOutCode(float x,float y);

enum  {  
		TOP = 0x1,
		BOTTOM = 0x2,
		RIGHT = 0x4,
		LEFT = 0x8
};

float xmin,xmax,ymin,ymax;

void clip(float x0,float y0,float x1,float y1)
{
	outcode code1,code2,codeout;
	int accept = FALSE,done = FALSE;
	code1 = CompOutCode(x0,y0);
	code2 = CompOutCode(x1,y1);
	do
	{
		if(!(code1|code2))
		{
			accept = TRUE;
			done = TRUE;
		}
		else
			if(code1 & code2)
			done = TRUE;
			else
			{
				float x,y;
				  
				codeout = code1?code1:code2;
				if(codeout & TOP)
				{
					x = x0+(x1-x0)*(ymax-y0)/(y1-y0);
					y = ymax;
				}
				else
					if(codeout & BOTTOM)
					{
						x = x0+(x1-x0)*(ymin-y0)/(y1-y0);
						y = ymin;
					}
					else
						if(codeout & RIGHT)
						{
							y = y0+(y1-y0)*(xmax-x0)/(x1-x0);
							x = xmax;
						}
						else
						{
							y = y0+(y1-y0)*(xmin-x0)/(x1-x0);
							x = xmin;
						}
				if(codeout==code1)
				{
					x0 = x;
					y0 = y;
					code1 = CompOutCode(x0,y0);
				}
				else
				{
					x1 = x;
					y1 = y;
					code2 = CompOutCode(x1,y1);
				}
			}
	}while(done==FALSE);
	if(accept)
		line(x0,y0,x1,y1);
	outtextxy(150,20,"POLYGON AFTER CLIPPING");
	  
	rectangle(xmin,ymin,xmax,ymax);
}

outcode CompOutCode(float x,float y)
{
	outcode code = 0;
	if(y>ymax)
		code|=TOP;
	else
		if(y<ymin)
			code|=BOTTOM;
	if(x>xmax)
		code|=RIGHT;
	else
		if(x<xmin)
			code|=LEFT;
	
	return code;
}
void main( )
{
	float x1,y1,x2,y2;
	int gdriver = DETECT, gmode, n = 3,poly[14],i;

	/*printf("Enter the no of sides of polygon:");
	scanf("%d",&n);
	printf("\nEnter the coordinates of polygon\n");
	for(i=0;i<2*n;i++)
	{scanf("%d",&poly[i]);}*/
	poly[0] = 150; poly[1] = 50;
	poly[2] = 150; poly[3] = 200;
	poly[4] = 250; poly[5] = 200;
	//poly[6] = 270; poly[7] = 190;
	//poly[8] = 330; poly[9] = 270;
	//poly[10] = 200; poly[11] = 230;
	//poly[12] = 70; poly[13] = 270;
	//poly[14] = 130; poly[15] = 190;
	//poly[16] = 70; poly[17] = 150;
	//poly[18] = 130; poly[19] = 150;

	//poly[2*n]=poly[0];
	//poly[2*n+1]=poly[1];
	
	/*printf("Enter the rectangular coordinates of clipping window\n");
	scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);*/
	xmin = 100; ymin = 100; xmax = 300; ymax = 300;

	initgraph(&gdriver, &gmode, "");
	  
	outtextxy(150,20,"POLYGON BEFORE CLIPPING");
	line(poly[0],poly[1],poly[2],poly[3]);
	line(poly[2],poly[3],poly[4],poly[5]);
	//drawpoly(n+1,poly);
	rectangle(xmin,ymin,xmax,ymax);
	getch( );
	cleardevice( );
	for(i=0;i<n-1;i++)
		clip(poly[2*i],poly[(2*i)+1],poly[(2*i)+2],poly[(2*i)+3]);
	getch( );
	restorecrtmode( );
}
